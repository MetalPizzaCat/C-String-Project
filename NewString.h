
//Please do not add or change included files
//it won't work without them
#pragma once
#include <vector>
#include <iostream>





namespace NewString {
	using namespace System;
	using namespace std;
	namespace Exeptions
	{
		struct OutOfBounds
		{
			OutOfBounds(){}
		};
		struct StringIsEmrty
		{
			StringIsEmrty(){}
		};
	}
	class string
	{
	protected:

		vector<wchar_t>*Text = new vector<wchar_t>();
#pragma region BaseOperators
	public:
		string() {}
		string(char*text)
		{
			if (sizeof(text) > 0)
			{
				for (unsigned i = 0; i < sizeof(text); i++)
				{
					Text->push_back(text[i]);
				}
				Text->push_back('\0');
			}
		}
		string(std::string text)
		{
			if (text.length() > 0)
			{
				for (unsigned i = 0; i < text.length(); i++)
				{
					Text->push_back(text.at(i));
				}
			}
		}
		string  operator=(string* text)
		{
			Text->clear();
			this->Text = text->Text;
			Text->push_back('\0');

		}
		string  operator=(string text)
		{
			Text->clear();
			this->Text = text.Text;
			Text->push_back('\0');
		}
		string operator=(char*text)
		{
			Text->clear();
			if (sizeof(text) > 0)
			{
				for (int i = 0; i < sizeof(text); i++)
				{
					Text->push_back(text[i]);
				}
				Text->push_back('\0');
			}
		
		}
		string operator=(std::string text)
		{
			Text->clear();
			if (text.length() > 0)
			{
				for (unsigned i = 0; i < text.length(); i++)
				{
					Text->push_back(text.at(i));
				}
				Text->push_back('\0');
			}
		}
		void PushBack(wchar_t letter)
		{
			this->Text->push_back(letter);
		}
		//Get one of the letters
		wchar_t operator[](unsigned Pos)
		{
			if (Pos < this->Text->size())
			{
				return Text->at(Pos);
			}
			else
			{
				return ' ';
			}
		}
#pragma endregion
		string Insert(unsigned Pos, char letter)
		{
			if (this->Text->size() > Pos)
			{
				string res;
				res.Text = this->Text;
				vector<wchar_t>::iterator i = find(this->Text->begin(), this->Text->end(),Text->at(Pos));
				res.Text->insert(i, letter);
				return res;
			}
		}
		wchar_t* ToChar()
		{
			if (this->Text->size() > 0)
			{
				wchar_t*res = new wchar_t();
				for (unsigned i = 0; i < this->Text->size(); i++)
				{
					res[i] = this->Text->at(i);
				}
				
				return res;
			}
		}

		int IndexOf(wchar_t letter)
		{

			if (this->Text->empty() == false)
			{
				for (unsigned i = 0; i < this->Text->size(); i++)
				{
					if (this->Text->at(i) == letter)
					{
						return i;
						break;
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				throw(Exeptions::StringIsEmrty());
			}

			/*vector<wchar_t>::iterator it = find(this->Text->begin(), this->Text->end(), Text->at(i));*/
		}
		string operator+(string text)
		{
			if (text.Text->empty() == 0 && this->Text->empty() == 0)
			{
				string res;
				res.Text = this->Text;
				res.Text->pop_back();
				for (unsigned i = 0; i < text.Text->size(); i++)
				{
				 	res.Text->push_back(text.Text->at(i));
				}
				return res;
			}
			else
			{
				return "";
			}
		}
		int Size(void)
		{
			return this->Text->size();
		}

		//If it's CLI project
#if __cplusplus_cli
		string(System::String^text)
		{
			if (text->Length > 0)
			{
				for (int i = 0; i < text->Length; i++)
				{
					Text->push_back(text[i]);
				}
				Text->push_back('\0');
			}
			else
			{

			}

		}
		System::String^ ToString()
		{
			if (this->Text->size() > 0)
			{
				wchar_t*rest = new wchar_t();
				for (unsigned i = 0; i < this->Text->size(); i++)
				{
					rest[i] = this->Text->at(i);
				}
				String^res = gcnew String(rest);
				return res;
			}
			else return "";
		}
		string operator=(System::String^text)
		{
			Text->clear();
			if (text->Length > 0)
			{
				for (int i = 0; i < text->Length; i++)
				{
					Text->push_back(text[i]);
				}
				Text->push_back('\0');
			}
			else
			{

			}

		}
		bool operator==(String^text)
		{
			if (this->Text->size() != text->Length)
			{
				return 0;
			}
			else
			{
				for (int i = 0; i < this->Size(); i++)
				{
					if (this->Text->at(i) == text[i])
					{
						continue;
					}
					else
					{
						return 0;
						break;
					}
				}
				return 1;
			}
		}

#endif
		bool operator==(string string)
		{
			if (this->Size() != string.Size())
			{
				return 0;
			}
			else
			{
				for (int i = 0; i < this->Size(); i++)
				{
					if (this->Text->at(i) == string.Text->at(i))
					{
						continue;
					}
					else
					{
						return 0;
						break;
					}
				}
				return 1;
			}
		}
		bool operator==(std::string text)
		{
			if (this->Size() != text.size())
			{
				return 0;
			}
			else
			{
				for (int i = 0; i < this->Size(); i++)
				{
					if (this->Text->at(i) == text.at(i))
					{
						continue;
					}
					else
					{
						return 0;
						break;
					}
				}
				return 1;
			}
		}
		string SubString(int startPos,int endPos)
		{
			if (this->Text->empty() != true)
			{
				if (this->Size() > startPos &&this->Size() > endPos)
				{
					vector<wchar_t>::iterator st = find(this->Text->begin(), this->Text->end(), this->Text->at(startPos));
					vector<wchar_t>::iterator en= find(this->Text->begin(), this->Text->end(), this->Text->at(endPos));
					vector<wchar_t>*resV = new vector<wchar_t>(st, en);
					resV->push_back('\0');
					string res;
					res.Text = resV;
					return res;
				}
				else
				{
					throw(Exeptions::OutOfBounds());
				}
			}
			else
			{
				throw(Exeptions::StringIsEmrty());
			}
		}
	};

}

typedef NewString::string nstring;
