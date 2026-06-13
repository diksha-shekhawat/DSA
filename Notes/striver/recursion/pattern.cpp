#include<iostream>
using namespace std;
void pat1(int n){
    int i,j;
    for (i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pat2(int n){
    int i,j;
    for(i=0;i<n;i++){
       for(j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pat3(int n){
    int i,j;
    for(i=0;i<n;i++){
       for(j=0;j<=i;j++){
            cout<<j+1<<" "   ;
        }
        cout<<endl;
    }
    
}
void pat4(int n){
    int i,j;
    for(i=0;i<n;i++){
       for(j=0;j<=i;j++){
            cout<<i+1<<" "   ;
        }
        cout<<endl;
    }
    
}
void pat5(int n){
    int i,j;
    for(i=1;i<=n;i++){
       for(j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pat6(int n){
    int i,j;
    for(i=1;i<=n;i++){
       for(j=1;j<=n-i+1;j++){
            cout<<j<<" "   ;
        }
        cout<<endl;
    }
}
void pat7(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(j=0;j<2*i+1;j++){
            cout<<"*";
        }
        for(j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pat8(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            cout<<" ";
        }
        for(j=0;j<2*n-2*i-1;j++){
            cout<<"*";
        }
        for(j=0;j<n-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void pat10(int n){
    int i,j;
    for(i=1;i<=2*n-1;i++){
        if (i<=n){
            for(j=1;j<=i;j++){
                cout<<"*";
            }
        }
        else{
            for(j=1;j<2*n-i+1;j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
} 
void pat11(int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if( (i+j)%2==0){
                cout<<"1";
            }
            else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}
void pat12(int n){
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<j;
        }
        for(j=1;j<=2*n-2*i;j++){
            cout<<" ";
        }
        for(j=i;j>=1;j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void pat13(int n){
    int i,j,k=1;
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            cout<<k++<<" ";
        }
        cout<<endl;
    }
}
void pat14(int n){
    for(int i=0;i<n;i++){
        for(char j= 'A';j<='A'+i;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pat15(int n){
    for(int i=0;i<n;i++){
        for(char j= 'A';j<='A'+n-i-1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pat16(int n){
    for(int i=0;i<n;i++){
        char ch='A'+i;
        for(int j=0;j<=i;j++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}
void pat17(int n){
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        char ch='A';
        for( int j=0;j<=i;j++){
            cout<<ch;
            ch++;
        }
        ch--;
        for(int j=0;j<i;j++){
            ch--;
            cout<<ch;
        }
        cout<<endl;
    }
}
void pat17_2(int n){
    for(int i=0;i<n;i++){
        
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        char ch='A';
        int breakpoint=(2*i+1)/2;
        for( int j=1;j<=2*i+1;j++){
            cout<<ch;
            if (j<=breakpoint){
                ch++;
            }
            else{
                ch--;   
            }
        }
        
        cout<<endl;

    }

}
void pat18(int n){
    for(int i=1;i<=n;i++){
        char ch='A'+n;
        for(char j=ch-i;j<ch;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void pat19(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        for(int j=1;j<2*i-1;j++){
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<2*n-2*i+1;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void pat20(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        for(int j=1;j<2*n-2*i+1;j++){
            cout<<" ";
        }
        for(int j=1;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        for(int j=1;j<2*i-1;j++){
            cout<<" ";
        }
        for(int j=1;j<=n-i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}
void pat21(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if (i==0 || i==n-1|| j==0 || j==n-1){
            cout<<"*";
            }
            else{
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
void pat22(int n){  
    // IMPORTANT PATTERN
    //refer to striver(22 patterns in one shot video)
    // Pattern size = (2*n - 1) × (2*n - 1)
    // Example:
    // n = 5 → matrix size = 9 × 9

    /*
        Logic:

        We calculate the minimum distance of each cell
        from all 4 boundaries:
        
        left boundary
        right boundary
        top boundary
        bottom boundary

        Then:
        value to print = n - minimum distance
    */

    // Outer loop -> rows
    for(int i = 0; i < 2*n - 1; i++){

        // Inner loop -> columns
        for(int j = 0; j < 2*n - 1; j++){

            // Distance from left boundary
            int left = i;

            // Distance from top boundary
            int top = j;

            // Distance from right boundary
            int right = 2*n - 2 - j;

            // Distance from bottom boundary
            int bottom = 2*n - 2 - i;

            // Minimum distance among left and top
            int min1 = min(left, right);

            // Minimum distance among right and bottom
            int min2 = min(top, bottom);

            // Overall minimum distance
            int min3 = min(min1, min2);

            /*
                Outer layer -> min distance = 0
                so value = n

                Next layer -> min distance = 1
                so value = n-1

                Center -> largest min distance
                so value becomes 1
            */

            // Print final value
            cout << n - min3 << " ";
        }

        // Move to next row
        cout << endl;
    }
}

int main(){
    cout<<"Pattern 1"<<endl;
    pat1(5);
    cout<<"Pattern 2"<<endl;
    pat2(5);
    cout<<"Pattern 3"<<endl;
    pat3(5);
    cout<<"Pattern 4"<<endl;
    pat4(5);
    cout<<"Pattern 5"<<endl;
    pat5(5);
    cout<<"Pattern 6"<<endl;
    pat6(5);
    cout<<"Pattern 7"<<endl;
    pat7(5);
    cout<<"Pattern 8"<<endl;
    pat8(5);
    cout<<"Pattern 10"<<endl;
    pat10(5);
    cout<<"Pattern 11"<<endl;
    pat11(5);
    cout<<"Pattern 12"<<endl;
    pat12(4);
    cout<<"Pattern 13"<<endl;
    pat13(5);
    cout<<"Pattern 14"<<endl;
    pat14(5);
    cout<<"Pattern 15"<<endl;
    pat15(5);
    cout<<"Pattern 16"<<endl;
    pat16(5);
    cout<<"Pattern 17"<<endl;
    pat17(5);
    cout<<"Pattern 17_2"<<endl;
    pat17_2(5);
    cout<<"Pattern 18"<<endl;
    pat18(5);
    cout<<"Pattern 19"<<endl;
    pat19(5);
    cout<<"Pattern 20"<<endl;
    pat20(5);
    cout<<"Pattern 21"<<endl;
    pat21(5);
    cout<<"Pattern 22"<<endl;
    pat22(5);
    return 0;
}