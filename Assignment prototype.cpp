#include <iostream>
#include <cstdlib>

using namespace std;

int initial_state[3][3] = {8,1,2,3,4,5,6,7,0};
int final_state[3][3] = {0,1,2,3,4,5,6,7,8};

int C_cost;

void check_C_cost()
{
    int cost = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (initial_state[i][j] != final_state[i][j])
                cost++;
        }
    }

    C_cost = cost;
}

int checkcost(int x, int y, int i, int j)
{
    int cost = 0;

    int temp = initial_state[x][y];
    initial_state[x][y] = initial_state[i][j];
    initial_state[i][j] = temp;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (initial_state[i][j] != final_state[i][j])
                cost++;
        }
    }

    temp = initial_state[x][y];
    initial_state[x][y] = initial_state[i][j];
    initial_state[i][j] = temp;

    return cost;
}



void move()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (initial_state[i][j] == 0)  //Move. //if min > current min do not make move
            {
                if (i == 1 && j == 1)     //Move of center
                {
                  
                if (i == 0 && j == 0)     //Move of top row
                {

                }
                if (i == 0 && j == 1)
                {
                   if (checkcost(i, j-1, i,j) >= checkcost(i, j+1, i,j) && checkcost(i, j-1, i,j) >= checkcost(i+1, j, i,j))
                   {
                       cout<<"Left";
                       int temp = initial_state[i][j];
                       initial_state[i][j] = initial_state[i][j-1];
                       initial_state[i][j-1] = temp;
                   }
                   else if (checkcost(i, j+1, i,j) >= checkcost(i, j-1, i,j) && checkcost(i, j+1, i,j) >= checkcost(i+1, j, i,j))
                   {
                       cout<<"Right";
                       int temp = initial_state[i][j];
                       initial_state[i][j] = initial_state[i][j+1];
                       initial_state[i][j+1] = temp;
                   }
                   else if (checkcost(i+1, j, i,j) >= checkcost(i, j-1, i,j) && checkcost(i+1, j, i,j) >= checkcost(i, j-1, i,j))
                   {
                       cout<<"Swap Down\n";
                       int temp = initial_state[i+1][j];
                       initial_state[i+1][j] = initial_state[i][j];
                       initial_state[i][j] = temp;
                   }
                }

               /* if (i == 0 && j == 2)

                if (i == 1 && j == 0)

                if (i == 1 && j == 2)

                if (i == 2 && j == 0)     //Move of Bottom row

                if (i == 2 && j == 1)     //Move of left

                if (i == 2 && j == 2)     //Move of right*/

            }

        }
    }
}
}

int main()
{

    //do
    //{
        check_C_cost();
        if (C_cost == 0){}
            //break;

        move();          



        for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        cout<<initial_state[i][j]<<" ";
        cout<<endl;
    }
        system("pause");





    //}while(C_cost != 0);


    /*for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        cout<<initial_state[i][j]<<" ";
        cout<<endl;
    }*/


    cout<<"\n\nProgram ends\n";
    return 0;
}
