#include<iostream>
#include<vector>
#include<cctype>
#include <unordered_map>
#include <map>
using namespace std;

class Breakfast{
    public:
    static int coffeeCount;
    Breakfast(){

    }
    void output(vector<int> order){
                unordered_map<int,int> ump;
        for(int c: order){
            ump[c]++;
        }
        int mainBreakfast = ump[1];
        int sideBreakfast = ump[2];
        if(mainBreakfast==0 && sideBreakfast==0) {
            cout<<"Unable to process: Main and Side are missing\n";
            return;
        } else if(mainBreakfast==0){
            cout<<"Unable to process: Main is missing\n";
            return;
        } else if(sideBreakfast==0){
            cout<<"Unable to process: Side is missing\n";
            return;
        } else if(mainBreakfast>1 && sideBreakfast>1){
            cout<<"Unable to process: Eggs and Toasts can not be ordered more than once.\n";
            return;
        }else if(mainBreakfast>1){
            cout<<"Unable to process: Eggs can not be ordered more than once.\n";
            return;
        }else if(sideBreakfast>1){
            cout<<"Unable to process: Side can not be ordered more than once.\n";
            return;
        }
        int coffeeCount = ump[3];
        cout<<"Eggs, Toast";
        if(coffeeCount==1){
            cout<<", Coffee\n";
        } 
        else if(coffeeCount>1){
            cout<<", Coffee("<<coffeeCount<<")\n";
        }
    }

};

class Lunch{
    public:
    static int sides;
    Lunch(){

    }
    void output(vector<int> order){
        unordered_map<int,int> ump;
        for(int c: order){
            ump[c]++;
        }
        int mainLunchCount = ump[1];
        int sideLunchCount = ump[2];
        if(mainLunchCount==0 && sideLunchCount==0) {
            cout<<"Unable to process: Main is missing, Side is missing\n";
            return;
        } else if(mainLunchCount==0){
            cout<<"Unable to process: Main is missing\n";
            return;
        } else if(sideLunchCount==0){
            cout<<"Unable to process: Side is missing\n";
            return;
        } else if(mainLunchCount>1){
            cout<<"Unable to process: Sandwich can not be ordered more than once.\n";
            return;
        }
        cout<<"Sandwich";
        if(sideLunchCount==1){
            cout<<", Chips";
        } 
        else if(sideLunchCount>1){
            cout<<", Chips("<<sideLunchCount<<")";
        }
        int sodaCount = ump[3];
        if(sodaCount==0){
            cout<<", Water.\n";
        } else{
            cout<<", Soda.";
        }

    }
};

class Dinner{
    public:
    static int dessert;
    Dinner(){

    }
    void output(vector<int>order){
        unordered_map<int,int> ump;
        for(int c: order){
            ump[c]++;
        }
        int mainDinnerCount = ump[1];
        int sideDinnerCount = ump[2];
        int wineCount = ump[3];
        int cakeCount = ump[4];
        if(mainDinnerCount==0 && sideDinnerCount==0) {
            cout<<"Unable to process: Main is missing, Side is missing\n";
            return;
        } else if(mainDinnerCount==0){
            cout<<"Unable to process: Main is missing\n";
            return;
        } else if(sideDinnerCount==0){
            cout<<"Unable to process: Side is missing\n";
            return;
        } else if(cakeCount==0){
            cout<<"Unable to process: Dessert is missing\n";
            return;
        } else if(mainDinnerCount>1){
            cout<<"Unable to process: Steak can not be ordered more than once.\n";
            return;
        }else if(sideDinnerCount>1){
            cout<<"Unable to process: Potatoes can not be ordered more than once.\n";
            return;
        }else if(wineCount>1){
            cout<<"Unable to process: Wine can not be ordered more than once.\n";
            return;
        }else if(cakeCount>1){
            cout<<"Unable to process: Cake can not be ordered more than once.\n";
            return;
        }
        cout<<"Steak, Potatoes";
        if(wineCount){
            cout<<", Wine, Water, Cake.\n";
        }else{
            cout<<", Water, Cake.\n";
        }
    }
};

int main(){
    cout<<"Menu Option:\n";
    cout<<"Enter either Breakfast, Lunch or Dinner\n";
    cout<<"Breakfast Menu:\n";
    cout<<"1: Eggs, 2: Toast, 3: Coffee. Only multiple coffee can be ordered.\n";
    cout<<"Lunch Menu:\n";
    cout<<"1: Sandwich, 2: Chips, 3: Soda. Only multiple sides can be ordered.\n";
    cout<<"Dinner Menu:\n";
    cout<<"1: Steak, 2: Potatoes, 3: Wine, 4: Cake. Dessert must be ordered and Water is provided by us.\n";
    cout<<"Each order must contain a main and a side\n";
    string meal;
    cin>>meal;
    transform(meal.begin(), meal.end(), meal.begin(), ::tolower);
    if(meal=="breakfast" ){
        vector<int>order;
        while(1){
            cout<<"Enter menu items for Breakfast or 0 (zero) to close.\n";
            int inp;
            cin>>inp;
            if(!isdigit(inp)) {
                cout<<"Input should be menu number 1,2,3\n";
            }
            if(inp==0)  break;
            if(inp>=4) {
                cout<<"Please enter only these options ->1: Eggs, 2: Toast, 3: Coffee. Only multiple coffee can be ordered.\n";
            }
            if(inp==1 || inp==2 || inp==3)
                order.push_back(inp);
        }
        Breakfast bfObj;
        bfObj.output(order);
    } else if(meal == "lunch"){
        vector<int>order;
        while(1){
            cout<<"Enter menu items for Lunch or 0 (zero) to close.\n";
            int inp;
            cin>>inp;
            if(!isdigit(inp)) {
                cout<<"Input should be menu number 1,2,3\n";
            }
            if(inp==0)  break;
            if(inp>=4) {
                cout<<"Please enter only these options ->1: Sandwich, 2: Chips, 3: Soda. Only multiple sides can be ordered.\n";
            }
            if(inp==1 || inp==2 || inp==3)
                order.push_back(inp);
        }

        Lunch lObj;
        lObj.output(order);
        
    } else if(meal == "dinner"){
        vector<int>order;
        while(1){
            cout<<"Enter menu items for Dinner or 0 (zero) to close.\n";
            int inp;
            cin>>inp;
            if(!isdigit(inp)) {
                cout<<"Input should be menu number 1,2,3\n";
            }
            if(inp==0)  break;
            if(inp>=5) {
                cout<<"Please enter only these options ->1: Steak, 2: Potatoes, 3: Wine, 4: Cake. Dessert must be provided and water is always provided.\n";
            }
            if(inp==1 || inp==2 || inp==3 || inp==4)
                order.push_back(inp);
        }
        Dinner dObj;
        dObj.output(order);

    } else{
        cout<<"Not a valid menu.";
    }
    
}