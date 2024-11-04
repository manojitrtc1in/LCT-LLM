from tqdm import tqdm
import re  
import json  
from tree_sitter_languages import get_language, get_parser
import tiktoken
import sys
import os

encoding = tiktoken.encoding_for_model('gpt-4o')


target_path = '<path to target directory>'
grammar_path = '<path to grammar directory>'

def get_lang(language):
    lang_dict = {'c': 'c', 'c++': 'cpp', 'java': 'java', 'python': 'python', 'go': 'go'}
    return lang_dict[language.lower()]

def find_identifiers(code, language):
    """ Find all identifiers in the code """

    LANGUAGE = get_language(language)
    parser = get_parser(language)
    tree = parser.parse(code.encode())
    root_node = tree.root_node

    grammar = os.path.join(grammar_path, f'grammar-{language}.json')
    with open(grammar, 'r') as file:
        data = file.read()
    grammar = json.loads(data)
    acceptable_parents = grammar['PARENT']
    dont_be = grammar['NOT']

    query = LANGUAGE.query(
        """
        (identifier) @identifier
        """
    )

    qc = query.captures(root_node)
    captures = []
    for capture in qc:
        node = capture[0]
        parent = node.parent
        ce = code.encode()
        # print(ce[node.start_byte:node.end_byte].decode(), node.type, ce[parent.start_byte:parent.end_byte].decode(), parent.type)
        if parent.type not in acceptable_parents or code[node.start_byte:node.end_byte] in dont_be:
            continue
        captures.append(capture)
    return captures

def get_id_set(code, captures):
    """ Get the set of all identifiers in the code """

    id_set = set()
    for capture in captures:
        node = capture[0]
        id_set.add(code.encode()[node.start_byte:node.end_byte].decode())
    return id_set

  
def process_code(file_name, language, dataset=None, target_dir=None): 
    """ Process the code and replace identifiers """
    if dataset == 'CodeNet': 
        with open(file_name, 'r') as file:  
            data = file.read()  
    else:
        data = file_name
    language = get_lang(language)
    
    id_list = find_identifiers(data, language)
    identifiers = get_id_set(data, id_list) 

    # Create mapping  
    i = 0
    mapping = {}
    len_reduced = 0
    for identifier in identifiers:  
        candidate = f"id{i}" 
        i_len = len(encoding.encode(identifier))
        c_len = len(encoding.encode(candidate))
        if c_len >= i_len:
            mapping[identifier] = identifier
        else:
            len_reduced += i_len - c_len
            mapping[identifier] = candidate
            i += 1
    mapping["file_name"] = file_name
    mapping["language"] = language
    mapping["len_reduced"] = str(len_reduced)
    if dataset:
        mapping["dataset"] = dataset
  
    # Replace identifiers in code
    for old, new in mapping.items():  
        if old in ["file_name", "language", "len_reduced", "dataset"]:
            continue
        try:
            data = re.sub(r'\b' + old + r'\b', new, data)
        except Exception as e:
            print(old)
            print(new)
            print(mapping)
            print(e)
            exit()
  
    # Write new code to file
    if target_dir:
        new_file = os.path.join(target_dir, file_name.split('/')[-1])
        with open(new_file, 'w') as file:
            file.write(data)    
    elif not dataset:
        print(data)
    
    return mapping, data
    
def codenet_all():
    """ Process all code in CodeNet """
    code_dir = os.getcwd()
    data_dir = os.path.dirname(code_dir)
    cn_dir = os.path.join(data_dir, 'codenet')
    lang_names = os.listdir(cn_dir)

    json_list = []

    target_dir = os.path.join(data_dir, 'codenet_processed')
    for lang in lang_names:
        if lang.startswith('.'):
            continue
        print(lang)
        lang_dir = os.path.join(cn_dir, lang)
        Code_dir = os.path.join(lang_dir, 'Code')
        code_files = os.listdir(Code_dir)
        target_lang_dir = os.path.join(target_dir, lang)
        for cf in tqdm(code_files):
            file = os.path.join(Code_dir, cf)
            mapping, code = process_code(file, lang, 'CodeNet', target_lang_dir)
            json_list.append(mapping)
    with open('codenet_mapping.json', 'w') as file:
        json.dump(json_list, file)

def codenet(bucket_dir):
    """ Process CodeNet code """
    cwd = os.path.join(bucket_dir, 'CodeNet')
    cn_dir = os.path.join(cwd, os.listdir(cwd)[0])
    target_dir = os.path.join(cwd, 'CodeNet-processed')
    if not os.path.exists(target_dir):
        os.makedirs(target_dir)
    lang_dirs = os.listdir(cn_dir)

    langs = {'C++': 'cpp', 'Java': 'java', 'Python': 'python', 'Go': 'go', 'C':'c'}

    json_list = []

    for ld in tqdm(lang_dirs):
        if ld not in langs:
            continue
        lang_dir = os.path.join(cn_dir, ld)  
        code_dir = os.path.join(lang_dir, 'Code')
        code_files = os.listdir(code_dir)
        for cf in tqdm(code_files):
            if '_nc' in cf:
                file = os.path.join(code_dir, cf)
                mapping, _ = process_code(file, langs[ld], 'CodeNet', target_dir)
                json_list.append(mapping)
    bucket = bucket_dir.split('/')[-1]
    with open('codenet_mapping_' + bucket + '.json', 'w') as file:
        json.dump(json_list, file)

def xcodeeval(bucket_dir):
    """ Process xCodeEval code """
    cwd = os.path.join(bucket_dir, 'xCodeEval')
    langs = {'C++': 'cpp', 'Java': 'java', 'Python': 'python', 'Go': 'go', 'C':'c'}

    json_list = []
    files = os.listdir(cwd)
    for f in files:
        if f.endswith('_nc.json'):
            train_file = os.path.join(cwd, f)
            break

    lines = open(train_file, 'r').readlines()
    processed = []

    for line in tqdm(lines):
        data = json.loads(line)
        code = data['source_code']
        lang = data['lang_cluster']
        if lang not in langs:
            continue
        file_name = data['code_uid']
        mapping, code = process_code(file_name, langs[lang], 'xCodeEval')
        json_list.append(mapping)
        data['source_code'] = code
        processed.append(data)
    bucket = bucket_dir.split('/')[-1]
    with open('xcodeeval_mapping_'+bucket + '.json', 'w') as file:
        json.dump(json_list, file)

    with open('xcodeeval_processed_' + bucket + '.json', 'w') as file:
        json.dump(processed, file)

def test():
    if len(sys.argv) < 3:
        print('Usage: python3 transform_identifiers.py <file> <language>')
        exit()
    if sys.argv[2] not in ['c', 'c++', 'java', 'python', 'go']:
        print('<language> can be: c, c++, java, python, go')
    file = sys.argv[1]
    lang = sys.argv[2]
    mapping, code = process_code(file, lang, 'CodeNet')
    print("The mapping is:")
    print(mapping)
    print()
    print("Transformed code:")
    print(code)

def main():
    print('starting')
    code_dir = os.getcwd()
    data_dir = os.path.dirname(code_dir)
    data_dir = os.path.join(data_dir, 'dataset')
    buckets = os.listdir(data_dir)
    print(buckets)
    for bucket in buckets:
        bucket_dir = os.path.join(data_dir, bucket)
        print('doing codenet_' + bucket)
        codenet(bucket_dir)
        print('doing xcodeeeval_', bucket)
        xcodeeval(bucket_dir)

if __name__ == '__main__':
    # main()
    test()
    # codenet_all()