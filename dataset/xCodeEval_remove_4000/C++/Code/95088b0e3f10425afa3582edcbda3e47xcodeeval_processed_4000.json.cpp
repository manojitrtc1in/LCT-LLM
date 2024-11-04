





















using namespace std;


std::vector<std::string> split(const std::string& s, char delimiter)
{
	vector<std::string> tokens;
	string token;
	std::istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}



int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> pixels(n, 0);

	string pixelstr;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		pixels.at(i) = atoi(s.c_str());
	}
	
	
	map<int, int> dictionary;

	

	for (int i = 0; i < 256; i++) {
		dictionary.insert(pair<int, int>(i, max(0, i - k + 1)));
	}

	set<int> used;

	for (auto au = pixels.begin(); au != pixels.end(); au++) {
		if (used.find(*au) != used.end()) {
			continue;
		}
		else {
			used.insert(*au);
		}
		int code = dictionary[*au];
		for (int j = code; j < code + k && j < 256; j++) {
			dictionary[j] = max(code, dictionary[j]);
		}
		for (int j = code + k; j < *au + k && j < 256; j++) {
			dictionary[j] = max(*au + 1, dictionary[j]);
		}
	}

	for (auto au = pixels.begin(); au != pixels.end(); au++) {
		cout << dictionary[*au] << " ";
	}
	
	cout << endl;
    return 0;
}



