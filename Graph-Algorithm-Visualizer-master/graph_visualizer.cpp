#include<bits/stdc++.h>
#include <windows.h>
#define max 10
using namespace std;

struct point{
	int x, y;
};

void printOriginalMatrix(vector<vector<int>> matrix)
{
	for(int i=0;i<max;i++)
	{
		cout << " | ";
		for(int j=0;j<max - 1;j++)
		{
			cout << matrix[i][j] << " || ";
		}
		cout << matrix[i][max-1] << " | ";
		cout << endl;
	}
}

void printBooleanMatrix(vector<vector<bool>>&matrix)
{
	for(int i=0;i<max;i++)
	{
		cout << " | ";
		for(int j=0;j<max - 1;j++)
		{
			if(matrix[i][j])
				cout << "1" << " || ";
			else
				cout << "0" << " || ";
		}
		if(matrix[i][max-1])
			cout << "1" << " || ";
		else
			cout << "0" << " || ";
		cout << endl;
	}
}

void printPath(vector<point> path)
{
	vector<vector<bool>> pathmap(max, vector<bool>(max, false));
	
	for(int i=0;i<path.size();i++)
	{
		int x1 = path[i].x;
		int y1 = path[i].y;
		pathmap[x1][y1] = true;
	}
	cout << "\n\n\n";
	printBooleanMatrix(pathmap);
}

bool isSafe(vector<vector<int>> &matrix, vector<vector<bool>> vis, int x, int y)
{
	if(x<0 || x>=max || y<0 || y>=max || vis[x][y] == true || matrix[x][y] == -1)
		return false;
	return true;
}


void bfs(vector<vector<int>> matrix, vector<vector<bool>> vis, point start)
{
	queue<point> q;
	q.push(start);
	vis[start.x][start.y] = true;
	bool found = false;
	while(!q.empty())
	{
		point temp = q.front(); q.pop();
		vis[temp.x][temp.y] = true;
		if(matrix[temp.x][temp.y] == 2)
		{
			found = true;
			system ("CLS"); 
			printBooleanMatrix(vis);
			Sleep(20);
			break;
		}
		system ("CLS"); 
		printBooleanMatrix(vis);
		Sleep(20);
		point temp2;
		if(isSafe(matrix, vis, temp.x + 1, temp.y))
		{
			temp2.x = temp.x + 1;
			temp2.y = temp.y;
			q.push(temp2);
		}
		if(isSafe(matrix, vis, temp.x - 1, temp.y))
		{
			temp2.x = temp.x - 1;
			temp2.y = temp.y;
			q.push(temp2);
		}
		if(isSafe(matrix, vis, temp.x, temp.y + 1))
		{
			temp2.x = temp.x;
			temp2.y = temp.y + 1;
			q.push(temp2);
		}
		if(isSafe(matrix, vis, temp.x, temp.y - 1))
		{
			temp2.x = temp.x;
			temp2.y = temp.y - 1;
			q.push(temp2);
		}
	}
	if(found)
		cout << "A way was found" << endl;
}








void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &vis, point start, bool &flag, vector<point> path)
{
	if(start.x < 0 || start.x >= max || start.y < 0 || start.y >=max || vis[start.x][start.y] == true || matrix[start.x][start.y] == -1 || flag == true)
		return;
	vis[start.x][start.y] = true;
	path.push_back(start);
	if(matrix[start.x][start.y] == 2)
	{
		vis[start.x][start.y] = true;
		flag = true;
		cout << "A way was found!!" << endl;
		printPath(path);
		return;
	}

	
	system ("CLS"); 
	printBooleanMatrix(vis);
	Sleep(20);
	point temp;
	temp.x = start.x + 1;
	temp.y = start.y;
	
	dfs(matrix, vis, temp, flag, path);
	
	temp.x = start.x - 1;
	temp.y = start.y;
	
	dfs(matrix, vis, temp, flag, path);
	
	temp.x = start.x;
	temp.y = start.y + 1;
	
	dfs(matrix, vis, temp, flag, path);
	
	temp.x = start.x;
	temp.y = start.y - 1;
	
	dfs(matrix, vis, temp, flag, path);
	
	path.pop_back();
}

int main(void)
{
	vector<vector<int>> matrix(max, vector<int>(max, 0));
	
	cout << "Enter the intial point-:\t";
	point start;
	point destination;
	cin >> start.x >> start.y;
	cout << "Enter the destination point-: \t";
	cin >> destination.x >> destination.y;
	matrix[start.x][start.y] = 1;
	matrix[destination.x][destination.y] = 2;
	cout << "Enter the walls in a place-: \t";
	int no_of_walls;
	cin >> no_of_walls;
	for(int i=0;i<no_of_walls;i++)
	{
		point temp;
		cin >> temp.x >> temp.y;
		matrix[temp.x][temp.y] = -1;
	}
	vector<vector<bool>> vis(max, vector<bool>(max, false));
	cout << "Enter the search method \n 1) BFS \n 2) DFS ";
	int method;
	cin >> method;
	
	if(method == 1)
	{
		
		bfs(matrix, vis, start);
	}
	else if(method == 2)
	{
		bool flag = false;
		vector<point> path;
		dfs(matrix, vis, start, flag, path);
		
	}
	else
	{
		cout << "Pressing the wrong number eh...;";
	}
	
	return 0;
}
