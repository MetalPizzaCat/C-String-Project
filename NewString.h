#pragma once
//Please do not add or change included files
//it won't work without them
#include <vector>
#include <iostream>
#define _nstring_ 27120




namespace NewString {
#if __cplusplus_cli
	using namespace System;
#endif
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
		string operator=(const char text[])
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
		bool AnyOf(String^text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text->Length; y++)
				{
					if (this->Text->at(i) == text[y])
					{
						return 1;
						break;
					}
				}
				
			}
			return 0;
		}
		int IndexOfAny(String^text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text->Length; y++)
				{
					if (this->Text->at(i) == text[y])
					{
						return i;
						break;
					}
				}
				
			}
			throw(new std::exception("No Such Letter in The String"));
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
		vector<wchar_t>::iterator FrontIterator(void)
		{
				return this->Text->begin();
		}
		vector<wchar_t>::iterator EndIterator(void)
		{
			return this->Text->end();
		}
		bool StartsWith(string text)
		{
			if (this->Text->empty() != true)
			{
				for (int i = 0; i < text.Size()-1; i++)
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
			else
			{
				throw(Exeptions::StringIsEmrty());
			}
		}
		bool IsEmrty()
		{
			return this->Text->empty();
		}
		void Trim()
		{
			if(this->IsEmrty() != true)
			{
				string res;
				for (int i = 0; i < this->Size(); i++)
				{
					if (this->Text->at(i) != ' ')
					{
						res.PushBack(this->Text->at(i));
					}
				}
				this->Text = res.Text;
			}
			else
			{
				throw(Exeptions::StringIsEmrty());
			}
		}
		bool AnyOf(string text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text.Size(); y++)
				{
					if (this->Text->at(i) == text[y])
					{
						return 1;
						break;
					}
				}
				
			}
			return 0;
		}
		bool AnyOf(string* text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text->Size(); y++)
				{
					if (this->Text->at(i) == text->Text->at(i))
					{
						return 1;
						break;
					}
				}
				
			}
			return 0;
		}
		string Replace(int Pos, wchar_t letter)
		{
			if (this->IsEmrty() != true)
			{
				if (Pos < this->Size())
				{
					this->Text->at(Pos) = letter;
					return *this;
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
		int IndexOfAny(string* text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text->Size(); y++)
				{
					if (this->Text->at(i) == text->Text->at(y))
					{
						return i;
						break;
					}
				}
				
			}
			throw(new std::exception("No Such Letter in The String"));
		}
		int IndexOfAny(string text)
		{
			for (int i = 0; i < this->Size(); i++)
			{
				for (int y = 0; y < text.Size(); y++)
				{
					if (this->Text->at(i) == text[y])
					{
						return i;
						break;
					}
				}
				
			}
			throw(new std::exception("No Such Letter in The String"));
		}
	};

}

typedef NewString::string nstring;
