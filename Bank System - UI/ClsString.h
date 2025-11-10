#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class ClsString
{
	string s;
public:

	ClsString(string s)
	{
		this->s = s;
	}
	ClsString()
	{
		s = "";
	}
	void put_value(string s)
	{
		this->s = s;
	}
	string get_value()
	{
		return s;
	}

	__declspec(property(get = get_value, put = put_value))string value;


	static  void print_the_first_letter(string s)
	{
		bool is_first_latter = true;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && is_first_latter)
			{
				cout << s[i] << "\n";
			}
			is_first_latter = (s[i] == ' ' ? true : false);
		}
	}
	static	string upper_the_first_letter(string s)
	{
		bool is_first_letter = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && is_first_letter)
			{
				s[i] = toupper(s[i]);
			}
			is_first_letter = (s[i] == ' ' ? true : false);
		}
		return s;
	}
	static	string lower_the_first_letter(string s)
	{
		bool is_first_letter = true;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ' ' && is_first_letter)
			{
				s[i] = tolower(s[i]);
			}
			is_first_letter = (s[i] == ' ' ? true : false);
		}
		return s;
	}
	static	string lower_the_letter(string s)
	{

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return s;
	}
	static	string upper_the_letter(string s)
	{

		for (int i = 0; i < s.length(); i++)
		{
			s[i] = toupper(s[i]);
		}
		return s;
	}
	static	string invert_the_charcter_case(string s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			(isupper(s[i]) ? s[i] = tolower(s[i]) : s[i] = toupper(s[i]));
		}
		return s;
	}
	static	void count_number_case(string s)
	{
		int capital = 0, small = 0, space = 0;
		for (int i = 0; i < s.length(); i++)
		{
			(s[i] == ' ' ? space++ : islower(s[i]) ? small++ : capital++);
		}
		cout << "the string length is : " << s.length() << "\n";
		cout << "the number of word(s) is : " << space + 1 << endl;
		cout << "the small letter is : " << small << "\n";
		cout << "the capital letter is : " << capital << "\n";

	}

	static	void print_each_word(string s)
	{
		string word;
		string delim = " ";
		int pos = 0;
		while ((pos = s.find(delim)) != std::string::npos)
		{
			word = s.substr(0, pos);
			if (word != "")
			{
				cout << word << "\n";

			}
			s.erase(0, pos + delim.length());
		}
		if (s != "")
		{
			cout << s << "\n";
		}
	}
	static	vector<string>splite(string s, string delim = "#//#")
	{
		vector<string>words;
		string word;
		int pos = 0;
		while ((pos = s.find(delim)) != std::string::npos)
		{
			word = s.substr(0, pos);
			if (word != "")
			{
				words.push_back(word);
			}
			s.erase(0, pos + delim.length());
		}
		if (s != "")
		{
			words.push_back(s);
		}
		return words;
	}
	static	string trim_left(string s)
	{
		int space = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
			{
				space++;
			}
			if (s[i] != ' ')
			{
				break;
			}
		}
		s.erase(0, space);
		return s;
	}
	static	string trim_right(string s)
	{
		int space = 0;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				space++;
			}
			if (s[i] != ' ')
			{
				break;
			}
		}
		int start = s.length() - space;
		int end = s.length();
		s.erase(start, end);
		return s;
	}
	static	string trim(string s)
	{
		return trim_right(trim_left(s));
	}
	static	string join_element_in_verctor(vector<string>elements, string delim = " ")
	{
		string s = "";
		for (string element : elements)
		{
			s += element + delim;
		}
		return s;
	}

	string trim_left()
	{
		return trim_left(s);
	}
	string trim_right()
	{
		return trim_right(s);
	}
	string trim()
	{
		return trim(s);
	}
	void print_each_word()
	{
		print_each_word(s);
	}
	vector<string>splite()
	{
		return splite(s);
	}


	void print_the_first_letter()
	{
		print_the_first_letter(s);
	}
	string upper_the_first_letter()
	{
		return upper_the_first_letter(s);
	}
	string lower_the_first_letter()
	{
		return lower_the_first_letter(s);
	}
	string lower_the_letter()
	{
		return lower_the_letter(s);
	}
	string upper_the_letter()
	{
		return upper_the_letter(s);
	}
	string invert_the_charcter_case()
	{
		return invert_the_charcter_case(s);
	}
	void count_number_case()
	{
		count_number_case(s);
	}

	static	string reverse_words(string s)
	{
		string delim = " ";
		string reverse_word;
		vector<string>words;
		words = splite(s);
		vector<string>::iterator it = words.end();

		while (it != words.begin())
		{
			--it;
			reverse_word += *it + delim;
		}
		return reverse_word;
	}
	static	vector<string> replace_the_words(string s)
	{
		cout << "enter the word which you want to replace \n";
		string word;
		string s2;
		cin >> s2;
		cout << "enter the new word\n";
		string new_word;
		cin >> new_word;
		vector<string>words;
		int pos = 0;
		string delim = " ";
		while ((pos = s.find(delim)) != std::string::npos)
		{
			word = s.substr(0, pos);
			if (word == s2)
			{
				words.push_back(new_word);
			}
			if (word != "" && word != s2)
			{
				words.push_back(word);
			}
			s.erase(0, pos + delim.length());
		}
		if (s == s2)
		{
			words.push_back(new_word);
		}
		if (s != "" && s != s2)
		{
			words.push_back(s);
		}
		return words;


	}
	static	string string_to_lower(string& s)
	{
		for (int i = 0; i < s.length(); i++)
		{
			s[i] = tolower(s[i]);
		}
		return s;
	}
	static	string replace_the_word(string s, bool match_case=false)
	{
		string old_word;
		cout << "enter the word which you want to replace \n";
		cin >> old_word;
		cout << "enter the new word\n";
		string new_word;
		cin >> new_word;
		vector<string>words = splite(s);
		if (match_case)
		{
			for (string& word : words)
			{
				if (word == old_word)
				{
					word = new_word;
				}
			}
		}
		if (!match_case)
		{
			for (string& word : words)
			{
				if (string_to_lower(word) == string_to_lower(old_word))
				{
					word = new_word;
				}
			}
		}
		return join_element_in_verctor(words);
	}


	string reverse_words()
	{
		
	return 	reverse_words(s);
	}
	string string_to_lower()
	{
		return	string_to_lower(s);
	}
	string replace_the_word()
	{
		return	replace_the_word(s);
	}
	vector<string> replace_the_words()
	{
		return replace_the_words(s);
	}

};

