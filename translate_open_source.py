import os
import logging
from dotenv import load_dotenv
import time
import argparse
from tqdm import tqdm
import torch
#import codegeex
#from codegeex.tokenizer import CodeGeeXTokenizer
#from codegeex.torch import CodeGeeXModel
from transformers import AutoTokenizer, AutoModelForCausalLM


os.makedirs(f'logs', exist_ok=True)
logging.basicConfig(filename=f"logs/translation.log", level=logging.INFO, format='%(asctime)s %(levelname)s %(module)s - %(funcName)s: %(message)s', datefmt='%Y-%m-%d %H:%M:%S')


def main(args):

    extensions = { 'Python': 'py','C': 'c','C++': 'c++','Java': 'java','Go': 'go', "Rust": "rs", "C#": "cs" }

    in_folder = f'dataset/{args.dataset}/{args.source_lang}/Code'
    out_folder = f'output/{args.model}/{args.dataset}/{args.source_lang}/{args.target_lang}'

    in_files = os.listdir(in_folder)
    print(f'found {len(in_files)} inputs')

    # check for files alraedy extracted
    already_extracted_files = []
    if os.path.exists(out_folder):
        already_extracted_files = os.listdir(out_folder)
        if len(already_extracted_files) > 0:
            already_extracted_files = [x.split('.')[0] for x in already_extracted_files if os.stat(f'{out_folder}/{x}').st_size != 0]

    if len(already_extracted_files) > 0:
        in_files = [x for x in in_files if x.split('.')[0] not in already_extracted_files]

    ext = extensions[args.target_lang]
    device = f'cuda:{args.gpu_id}'

    tokenizer, model = None, None
    

    
    if args.model == 'LLaMa':
        tokenizer = AutoTokenizer.from_pretrained('meta-llama/Llama-2-13b-chat-hf',  )
        model = AutoModelForCausalLM.from_pretrained('meta-llama/Llama-2-13b-chat-hf',  ).to(device)
    elif args.model == 'CodeLLaMa':
        tokenizer = AutoTokenizer.from_pretrained('codellama/CodeLlama-13b-Instruct-hf',  )
        model = AutoModelForCausalLM.from_pretrained('codellama/CodeLlama-13b-Instruct-hf',  ).to(device)
    elif args.model == 'Mixtral':
        tokenizer = AutoTokenizer.from_pretrained("mistralai/Mixtral-8x7B-Instruct-v0.1",  )
        model = AutoModelForCausalLM.from_pretrained("mistralai/Mixtral-8x7B-Instruct-v0.1", )
    
    
    # loop over input files
    os.makedirs(out_folder, exist_ok=True)
    for f in tqdm(in_files):
        prompt_file = f'{in_folder}/{f}'

        with open(prompt_file, "r", encoding="ISO-8859-1", errors='ignore') as fin:
            prompt = fin.readlines()

            
            if args.model == 'LLaMa':
                prompt = f"{args.source_lang} Code:\n\n" + "".join(prompt) + f'\n\nTranslate the above {args.source_lang} code to {args.target_lang}.\n\n{args.target_lang} Code:\n\n'
            elif args.model == 'CodeLLaMa':
                prompt = f"{args.source_lang} Code:\n\n" + "".join(prompt) + f'\n\nTranslate the above {args.source_lang} code to {args.target_lang}.\n\n{args.target_lang} Code:\n\n'
            elif args.model == 'Mixtral':
                prompt = f"{args.source_lang} Code:\n\n" + "".join(prompt) + f'\n\nTranslate the above {args.source_lang} code to {args.target_lang}.\n\n{args.target_lang} Code:\n\n'
            

            try:
                t0 = time.perf_counter()

                inputs = []
                
            
                inputs = tokenizer.encode(prompt, return_tensors="pt").to(device)

                total_input_tokens = inputs.shape[1]
                model_max_length = 8192 if args.model == 'Mixtral' else 2048
                model_max_length = 4096 if args.model == 'LLaMa' else 2048
                model_max_length = 4096 if args.model == 'CodeLLaMa' else 2048
                
                if total_input_tokens >= model_max_length:
                    out_file = f'{out_folder}/{f.split(".")[0]}.{ext}'
                    with open(out_file, 'w') as fot:
                        print("# Token size exceeded.", file=fot)
                    continue
                max_new_tokens = model_max_length - total_input_tokens

                raw_outputs = ''
                
                
                
                raw_outputs = model.generate(
                    inputs,
                    max_new_tokens=max_new_tokens,
                    do_sample=True,
                    top_p=args.p,
                    top_k=args.k,
                    temperature=args.temperature,
                    repetition_penalty=1,
                    pad_token_id=tokenizer.eos_token_id,
                )


                t1 = time.perf_counter()
                print("Total generation time:", t1 - t0)
                out_file = f'{out_folder}/{f.split(".")[0]}.{ext}'                
                with open(out_file, 'w') as fot:
                    
                    print(tokenizer.decode(raw_outputs[0]), file=fot)

            except (ValueError, FileNotFoundError) as e:
                print(e)
                continue


if __name__ == "__main__":
    load_dotenv()
    parser = argparse.ArgumentParser(description='run translation with open-source models given dataset and languages')
    parser.add_argument('--model', help='model to use for code translation. should be one of [LLaMa,CodeLLaMa, Mixtral]', required=True, type=str)
    parser.add_argument('--dataset', help='dataset to use for code translation. should be one of xCodeEval', required=True, type=str)
    parser.add_argument('--source_lang', help='source language to use for code translation. should be one of [Python,Java,C,C++,Go]', required=True, type=str)
    parser.add_argument('--target_lang', help='target language to use for code translation. should be one of [Python,Java,C,C++,Go]', required=True, type=str)
    parser.add_argument('--k', help='The number of highest probability vocabulary tokens to keep for top-k-filtering. Only applies for sampling mode, with range from 1 to 100.', required=True, type=int)
    parser.add_argument('--p', help='Only the most probable tokens with probabilities that add up to top_p or higher are considered during decoding. The valid range is 0.0 to 1.0. 1.0 is equivalent to disabled and is the default. Only applies to sampling mode. Also known as nucleus sampling.', required=True, type=float)
    parser.add_argument('--temperature', help='A value used to warp next-token probabilities in sampling mode. Values less than 1.0 sharpen the probability distribution, resulting in "less random" output. Values greater than 1.0 flatten the probability distribution, resulting in "more random" output. A value of 1.0 has no effect and is the default. The allowed range is 0.0 to 2.0.', required=True, type=float)
    parser.add_argument('--gpu_id', help='gpu id to use', required=True, type=int)
    args = parser.parse_args()

    # Initialize configurations
    source = args.source_lang
    target = args.target_lang
    logging.info(f"translating examples from {source} to {target} using {args.model} and {args.dataset} dataset")
    main(args)
