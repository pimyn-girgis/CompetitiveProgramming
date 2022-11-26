/*
**************************************************************
* Author  : Bemen Girgis
* Contact : bemen@girgis.org
**************************************************************
*/
 
#include <iostream>
using std::cout, std::endl;
#include <stdio.h>
#include <string.h>

#include <string>
using std::string;

#include <vector>
using std::vector;

const int INF  = 1e5;

typedef vector<vector<int>> matrix;

matrix get_cost_matrix(const vector<string> &word, int width)
{
   matrix cost(word.size() + 1, vector<int>(word.size() + 1));

   for(int i = 1; i < word.size(); ++i)
   {
      int len = width;
      for(int j = i; j <= word.size(); ++j)
      {
         len -= word[j - 1].size();
         if(i != j) --len;
         if(len >= 0) cost[i][j] = len * len;
         else cost[i][j] = INF;
      }
   }

   return cost;
}

vector<int> get_solution_array(const matrix &cost)
{
   vector<int> total_cost(cost.size(), INF);
   total_cost[0] = 0;
   vector<int> solution(cost.size());

   for(int i = 1; i < total_cost.size(); ++i)
      for(int j = 1; j <= i; ++j)
         if(total_cost[i] > total_cost[j - 1] + cost[j][i])
         {
            total_cost[i] = total_cost[j - 1] + cost[j][i];
            solution[i] = j;
         }
   
   return solution;
}

int display_solution(const vector<int> &solution, const vector<string> &word, int len)
{
   int k = solution[len] == 1? 1 : display_solution(solution, word, solution[len] - 1) + 1;

   printf("Line %d: ", k);

   for(int i = solution[len] - 1; i < len; ++i)
      printf("%s%c", word[i].c_str(), i == len - 1? '\n' : ' ');

   return k;
}

void wrap_text(char *input, int width)
{
   vector<string> word_list;

   for(char *token = strtok(input, " \n"); token; token = strtok(NULL, " \n"))
      word_list.push_back(token);

   matrix cost = get_cost_matrix(word_list, width);
   vector<int> solution = get_solution_array(cost);
   display_solution(solution, word_list, solution.size() - 1);
}

int main()
{
   char test1[] = "blah blah blah blah reallylongword";
   int  width1  = 16; 

   char test2[] = "Jackie Tom loves to cook";
   int  width2  = 10; 

   wrap_text(test1, width1);
   wrap_text(test2, width2);

   return 0;
}