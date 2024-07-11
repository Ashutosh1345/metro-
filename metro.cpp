#include<bits/stdc++.h>
#include<string>

using namespace std;

const int V=252;
string metro_lst[V];
int metro_no[V];

void metro_fare(float dis){
	cout<<"Expected Metro Fare (Weekdays except Sunday) would be: Rs. ";
	if(dis<=3.0){
		cout<<10.0<<endl;
	}
	else if(dis>3.0 && dis<=5.0){
		cout<<20.0<<endl;
	}
	else if(dis>5.0 && dis<=12.0){
		cout<<30.0<<endl;
	}
	else if(dis>12.0 && dis<=21.0){
		cout<<40.0<<endl;
	}
	else if(dis>16.0 && dis<=32.0){
		cout<<50.0<<endl;
	}
	else if(dis>32.0){
		cout<<60.0<<endl;
	}else{
		cout<<"Not Known"<<endl;
	}
	cout<<endl;
}

int minDistance(float dist[],bool sptSet[]){
    float min = 1000.0;
	int min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false &&dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void printPath(int parent[], int j,int src,vector<int> &cnt){
    if (parent[j]==src || parent[j]<=0){
    	if(parent[j]==src){
    		cnt.push_back(metro_no[j]);
			cout<<" -->>"<<metro_lst[metro_no[j]];
		}
		return;
	}
    printPath(parent, parent[j],src,cnt);
	cnt.push_back(metro_no[j]);
    cout<<" -->> "<<metro_lst[metro_no[j]];
}

void printSolution(float dist[], int src,int parent[],int dest,vector<int> &cnt){
    cout<<"Distance between two station is: "<<dist[dest]<<" km "<<endl;
    metro_fare(dist[dest]);
    cout<<metro_lst[metro_no[src]];
    cnt.push_back(metro_no[src]);
	printPath(parent, dest,src,cnt);
}

void dijkstra(float graph[][V], int src, int d,vector<int> &cnt){
    float dist[V];
    bool sptSet[V];
    int parent[V];
    for(int i = 0; i < V; i++)
    {
        parent[0] = -1;
        dist[i]   = 1000.0;
        sptSet[i] = false;
    }

    dist[src] = 0.0;
    for(int count = 0; count < V - 1; count++)
	{
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
            {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    printSolution(dist,src, parent, d,cnt);
}

string orange_line[17]   ={"Automotive square Khapri","Nari Road","Kadbi chowk","Gaddi godam square","Kasturjan Park","Zero Mile","sitaburdi","Congress nagar Ajni railway station","rahate colony","ajni square","chatrapathi square","jayprakash nagar","ujwal nagar","Nagpur airport","Airport south","New airport,Khapri","station"};
float ol[17]={0.0,0.9,1.1,1.1,1.2,1.1,1.6,2.2,1.1,0.9,0.8,1.7,1.1,1.0,1.3,1.1,1.0};
1
string aqua_line[21]  ={"Prajapati nagar","vaishnodevi square","Ambedkar square","telephone exchange","chitar oil square","Agrasen square","Dosar vaishya square","Nagpur railway station","Cotton market","sitabuldi","jhansi rani square","insttitute of engineers","Shankar nagar square","Lad college","ambazari lake","subash nagar","rachana ring road ","Vasudev nagar","Bansi nagar","Lokmanya nagar","Hingna mount view"};
float al[21]={0.0,0.3,0.6,1.1,1.1,1.4,1.3,1.3,1.2,1.1,1.8,1.7,1.6,1.7,1.8,1.5,1.6,1.8,1.7};

string aqua_line2[6]   ={"manewada","burdi","mahal","sadar","civil lines","highway"};
float al2[6]={0.0,1.3,0.5,0.8,0.5,1.1};

//string lines list={"Automotive square Khapri","Nari Road","Kadbi chowk","Gaddi godam square","Kasturjan Park","Zero Mile","sitaburdi","Congress nagar Ajni railway station","rahate colony","ajni square","chatrapathi square","jayprakash nagar","ujwal nagar","Nagpur airport","Airport south","New airport,Khapri","prajapati nagar","vaishnodevi square","Ambedkar square","telephone exchange","chitar oil square","Agrasen square","Dosar vaishya square","Nagpur railway station","Cotton market","sitabuldi","jhansi rani square","insttitute of engineers","Shankar nagar square","Lad college","ambazari lake","subash nagar","rachana ring road junction","vasudev nagar","Bansi nagar","lokmanya nagar","Hingna mount view","manewada","burdi","mahal","sadar","civil lines","highway"};

void print_ticket();
//int set_graph(float graph[V][V],map<string,int> metro,int x,int count,string arr[]);
//void set_weight(float graph[V][V],map<string,int>metro,int x,string arr[],float no[]);

 int main(){
	map <string,int> metro;

	float graph[V][V];
	memset(graph,0.0,sizeof(graph));
	int count=0;
//	count+=set_graph(graph,metro,16,count,orange_line);
//	count+=set_graph(graph,metro,19,count,aqua_line);
//	count+=set_graph(graph,metro,6,count,aqua_line 2);


//	set_weight(graph,metro,16,count,orange_line,ol);
//	set_weight(graph,metro,19,count,aqua_line,al);
//	set_weight(graph,metro,6,count,aqua_line 2,al);

	for(int i=0;i<17;i++){
		if(!metro[orange_line[i]]){
			metro[orange_line[i]]=count;
			count++;
		}
	}
	for(int i=0;i<21;i++){
		if(!metro[aqua_line[i]]){
			metro[aqua_line[i]]=count;
			count++;
		}
	}
		for(int i=0;i<6;i++){
		    if(!metro[aqua_line2[i]]){
		        metro[aqua_line2[i]]=count;
		        count++;
		    }
		}
	for(int i=0;i<17;i++){
  		int m=metro[orange_line[i]];
		int n=metro[orange_line[i+1]];
		graph[m][n]=ol[i+1];
		graph[n][m]=ol[i+1];

	}
	for(int i=0;i<21;i++){
  		int m=metro[aqua_line[i]];
		int n=metro[aqua_line[i+1]];
		graph[m][n]=al[i+1];
		graph[n][m]=al[i+1];
	}
	for(int i=0;i<6;i++){
	    int m=metro[aqua_line2[i]];
	    int n=metro[aqua_line2[i]];
	    graph[m][n]=al2[i+1];
	    graph[n][m]=al2[i+1];
	}
	

	int k=0;
	map<string,int>::iterator itr;
	for(itr =metro.begin(); itr!=metro.end();itr++){
		metro_lst[k]=itr->first;
		metro_no[itr->second]=k;
		k++;
	}

	int src;
	int dt;
	string c;
	string str1;
	string str2;
	do{
		cout<<endl<<endl<<endl<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"\t---   METRO APP   --- \t\t"<<endl;
		cout<<"-------------------------------------------"<<endl;
		cout<<"For finding shortest route,please enter 1. "<<endl;
		cout<<"For Ticketing and Token information,please enter 2."<<endl;
		cout<<"For Nagpur Maha Metro Stations,please enter 3."<<endl;
		cout<<"For Exit,please enter 0."<<endl;
		cout<<"Enter Your Response: ";
		getline(cin,c);
		cout<<endl;
		if(c=="1"){
			vector<int> cnt;
			cout<<"Enter starting station :";
			cin>>src;
			cout<<endl<<"Enter ending station :";
			cin>>dt;
//			cout<<sizeof(metro[str1]);
//			dt=metro[str1];
	  		cout<<endl<<"Starting Station is "<<metro_lst[metro_no[src]]<<" and Ending Station is "<<metro_lst[metro_no[dt]]<<endl;
			dijkstra(graph,int(src),int(dt),cnt);
			cout<<"\n\nNumber of station in between these two staions are : "<<cnt.size()<<endl;
		}
		else if(c=="2"){
			print_ticket();
		}
		if(c=="3"){
			map<string,int>::iterator it;
			for(it =metro.begin(); it!=metro.end();it++){
				cout<<it->first<<"\t"<<it->second<<endl;
			}
		}
	}while(c!="0");

	return 0;
}

void print_ticket(){
	cout<<endl<<endl;
	cout<<"----------TOKEN---------"<<endl;
	cout<<"1. Only One way permitted"<<endl;
	cout<<"2. Validity One day"<<endl;
	cout<<"3. Refund with in 30 min"<<endl;
	cout<<"4. Exit within 170 min, penalty Rs 10 per hour, subject to maximum Rs 50"<<endl;

	cout<<endl<<endl;
    cout<<"----------TRAVEL CARD---------"<<endl;
	cout<<"1. First Time Rs 150 ( including Rs 50 refundable security"<<endl;
	cout<<"2. Next recharge Rs 100 to Rs 1000"<<endl;
	cout<<"3. Validity - 1 year after every recharge, max 10 years"<<endl;
	cout<<"4. Same station entry/exit Rs 10 charged with in 20 min"<<endl;
	cout<<endl<<endl;
	cout<<"----------BENIFITS OF NAGPUR METRO SMART CARD---------"<<endl;
	cout<<"1. It provides 15 pre cent discount on every ride."<<endl;
	cout<<"2. Off Peak hours - between 6am to 8am, 12pm to 6pm and 10 pm onwards - can avail a discount of 20 per cent."<<endl;
	cout<<"3. On Sundays and National Holidays - there is a discount of  30%"<<endl;
	cout<<"4. You can buy card worth Rs 100 to Rs1000 at one time and return it anytime to get the balance amount back at Nagpur Maha metro"<<endl;
	cout<<"5. Refundable Security deposit Rs50"<<endl;
	cout<<"6. Discount is not applicable if Entry/Exit is made from the same station"<<endl;
	cout<<endl<<endl;
	cout<<"----------TOURIST CARD---------"<<endl;
	cout<<"1. Specially for a single day travel"<<endl;
	cout<<"2. Purchase a card worth Rs100 and travel whole day to any station on the Nagpur Maha Metro"<<endl;
	cout<<"3. 1 day Rs 170 (Rs 120 + Rs 50 refundable security)"<<endl;
	cout<<"4. 3 Days Rs 450 (Rs. 400 + Rs 50 refundable security)"<<endl;
	cout<<endl<<endl;

}
