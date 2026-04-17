#include<iostream> 
#include<algorithm>
#include<queue>

using namespace std;

int countl = 0;

int storage[101];
 int graph[1001][1001]; //Graph 
 //N : Number of vertex 
 //M : Number of edge 
 //V : Start vertex number 
 int N, M, V;

 bool check[1001];
 //Breadth First Search 
  int BFS(int x)
 {
	 
	 	queue<int> q;
	 	 //Check that has passed 
	 	int arr[1000]; //Save path 
		int f = 0;
	
		int level = 0;
	 	q.push(x);
		

		 	while (!q.empty())
		 	{
				
		 		int now = q.front(); //now : current node 
		 		q.pop();
				check[now] = true; //NOW has passed 
			 			
			

				 			for (int i = 1; i <= N; i++)
				 			{
				 				if (graph[now][i] == 1 && check[i] == false) //If connection & not passed 
					 				{
										q.push(i); //push 
										check[i] = true;
										f = 1;
					 				}
				 			}

						
			 	
				if (f == 1) {
					level = level + 1;
					f = 0;
				}
				
		 	}
			
			countl = countl + 1;
			
			
			return level;
}

  int daepyo(int x) {
	  int a[1001];
	  for (int i = 0; i <= N + 1; i++) {
		  a[i] = 0;
	  }

	  bool check2[1001];
	  for (int i = 0; i <= N + 1; i++) {
		  check2[i] = false;
	  }
	  queue<int> q;
	  int a2 = 0;

	  a[0] = BFS(x);

	  for (int i = 1; i <= N; i++)
		  check[i] = false;

	  q.push(x);
	  while (!q.empty()) {
		  int now = q.front();
		  q.pop();
		  for (int i = 1; i <= N; i++) {
			  if (graph[now][i] == 1 && check2[i] == false) {
				  check2[i] = true;
				  q.push(i);
				  a[i] = BFS(i);
				  for (int j = 1; j <= N; j++)
					  check[j] = false;

			  }
		  }

	  }
	  a2 = a[0];

	  for (int i = 1; i <= N; i++) {
		  if (a[i] != 0) {
			  if (a2 > a[i])
				  a2 = a[i];
		  }
	  }
	
  
	
	  int pos;
	  for (int i = 0; i <= N; i++) {
		  if (a2 == a[i]) {
			  if (i == 0)
				  return x;
			  else
			  pos = i;
		  }
	  }
	  return pos;
	
	  }
	
	


 int main()
 {
	 cin >> N;
	 cin >> M;



	 	//Edge connection 
		 	for (int i = 0; i < M; i++)
		 	{
		 		int a, b;
		 		cin >> a >> b;
				graph[a][b] = 1;
		 		graph[b][a] = 1;
			}
	

		int i2 = 0;
	
		for (int i = 1; i <= N; i++) {
			if (check[i] == false) {
				storage[i2] = i;
				BFS(i);
				i2++;
			}

		}
		cout << countl << endl;

		for (int i = 1; i <= N; i++) {
			check[i] = false;
		}
	
	

		for (int i = 0; i < i2; i++) {
			cout << daepyo(storage[i]) << endl;
		
		}
		

	 	return 0;
 }
