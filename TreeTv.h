
/* 	Igor Lopes 		CS_121
	April 13, 2015		Lab#11
*/

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include "BST.h"

using namespace std;



class TreeTv
{
	public:
	
	string* movie_titles;
	bool is_next_title;
	int total_lines;
	int total_titles;
	string* tmp_data;
	TreeTv()
	{
		total_lines = 0;
		total_titles = 0;
		SET_NUMBER_OF_LINES();
		SET_DATA();
		//SET_ACTORS();	
	}
	
	public: void SET_NUMBER_OF_LINES()
	{
		ifstream readFile("tvDB.txt");
		string line_data;
		while (getline(readFile, line_data))
   		 {
			++total_lines;
    		 }
	}
	
	public: void SET_DATA()
	{
		tmp_data = new string[total_lines];
		ifstream readFile("tvDB.txt");
		string line_data;
		string curr_line;
		int last_index = 0;
		while (getline(readFile, line_data))
   		 {
			curr_line = line_data.c_str(); 
			if(curr_line.empty())
			{
				tmp_data[last_index] = "VOID";
				last_index++;
			}
			else
			{
				tmp_data[last_index] = curr_line;
				last_index++;
			}
    		 }

		SET_TOTAL_TITLES();
		//SET_TITLES();
		GET_ACTORS_TITLES();
	//	BST tree (tmp_data, 150);
	}

	public: void SET_TOTAL_TITLES()
	{

		bool isTitle = false;
		string prev;
		string curr = tmp_data[0];
		for(int i = 1; i < total_lines; i++)
		{	
			prev = curr;
			curr = tmp_data[i];
			if(prev == "VOID" && curr != "VOID" && isTitle == false)
			{
				isTitle = true;
			}
				
			if(isTitle == true)
			{
				++total_titles;
				isTitle = false;
			}
		}

	}

	public: void SET_TITLES()
	{
		ofstream File;
		File.open ("titles.txt");
		bool isTitle = false;
		string prev;
		string curr = tmp_data[0];
		for(int i = 1; i < total_lines; i++)
		{	
			prev = curr;
			curr = tmp_data[i];
			if(prev == "VOID" && curr != "VOID" && isTitle == false)
			{
				isTitle = true;
			}
				
			if(isTitle == true)
			{
				//string fitered = FILTER_TITLE(tmp_data[i]);
				//File << fitered <<endl; 
				isTitle = false;
			}
			
		}

		
	}
	public: void GET_ACTORS_TITLES()
	{
		int count = 0 ;
		ofstream File;
		File.open ("titles.txt");
		bool isTitle = false;
		string prev;
		string curr = tmp_data[0];

		string curr_title = " ";
		string curr_actors = " ";		
		for(int i = 1; i < total_lines; i++)
		{	
			prev = curr;
			curr = tmp_data[i];
			if(curr == "VOID")
			{
			        File << curr_actors <<endl;
				File << curr <<endl;
			}
			if(prev == "VOID" && curr != "VOID" && isTitle == false)
			{
				isTitle = true;
			}
			
			if(isTitle == false && count < 3)
			{
				count++;
			}
			if(isTitle == false && count == 3 &&  curr != "VOID")
			{
				string fitered = tmp_data[i];
				curr_actors = curr_actors + "," + tmp_data[i];		
			}	
			if(isTitle == true)
			{	
				curr_title = tmp_data[i];
				curr_actors =  "";
				//string fitered = FILTER_TITLE(tmp_data[i]);
				string fitered = tmp_data[i];
				File << fitered <<endl; 
				isTitle = false;
				count = 0;
			}
			
		}
		
		
	}
};
	
