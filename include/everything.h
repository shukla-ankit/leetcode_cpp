#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <climits>
#include <ostream>
#include <algorithm>
#include <type_traits>
#include <unordered_set>
#include <unordered_map>
#include <chrono>
using namespace std::chrono;
using namespace std;

#ifndef __EVERYTHING__H
#define __EVERYTHING__H
namespace Color {
    enum Code {
        FG_RED      = 31,
        FG_GREEN    = 32,
        FG_BLUE     = 34,
        FG_DEFAULT  = 39,
        BG_RED      = 41,
        BG_GREEN    = 42,
        BG_BLUE     = 44,
        BG_DEFAULT  = 49
    };
    class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

        template <typename T>
        string print_array(vector<T> array){
            string ret = "[" ;
            for(auto n: array){
                if (std::is_same<T, char>::value)
                    ret += string(1, n) +",";
                else
                    ret += to_string(n) + ",";
            }
            if(array.size() > 0)
                ret = ret.substr(0, ret.length()-1);
            return ret + "]" ;
        }
        
        struct ListNode {
            int val;
            ListNode *next;
            ListNode() : val(0), next(nullptr) {}
            ListNode(int x) : val(x), next(nullptr) {}
            ListNode(int x, ListNode *next) : val(x), next(next) {}
        };

        ListNode* CreateList(vector<int> nums){
            ListNode *ret = nullptr, *ptr = nullptr;
            for(auto n : nums){
                if(ret == nullptr){
                    ret = new ListNode(n);
                    ptr = ret;
                }
                else{
                    ptr -> next = new ListNode(n);
                    ptr = ptr->next;
                }
            }
            return ret;
        }

        vector<int> ConvertToArray(ListNode* head){
            vector<int> ret;
            while(head){
                ret.push_back(head->val);
                head = head -> next;
            }
            return ret;
        }

        void print(ListNode* head){
            std::cout << "List :";
            while(head){
                std::cout << head->val << " -> ";
                head = head->next;
            }
            std:cout << "0" << endl;
        }


        template <>
        string print_array(vector<string> array){
            string ret = "[" ;
            for(auto n: array){
                    ret += n + ",";
            }
            if(array.size() > 0)
                ret = ret.substr(0, ret.length()-1);
            return ret + "]" ;
        }
        

        template <typename T>
        string print_array_of_arrays(vector<vector<T>> arrayOfArrays){
            string ret = "[" ;
            for(auto array : arrayOfArrays)
                ret += print_array<T>(array) + ", ";
            return ret + "]" ;            
        }

        template <typename T>
        bool match_array(vector<T> array1, vector<T> array2){
            /*
            if (array1.size() != array2.size())
                return false;

            for(int i = 0; i< array1.size() ; i++){
                if(array1[i] != array2[i])
                    return false;
            }
            return true;
            */
            return equal(array1.begin(), array1.end(), array2.begin());
        }
        
        template <typename T>
        bool match_arrays_of_arrays(vector<vector<T>> arrayOfArrays1, vector<vector<T>> arrayOfArrays2){
            if (arrayOfArrays1.size() != arrayOfArrays2.size())
                return false;

            for(int i = 0; i< arrayOfArrays1.size() ; i++){
                if(!match_array(arrayOfArrays1[i], arrayOfArrays2[i]))
                    return false;
            }
            return true;
        }

        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
            ~TreeNode(){
                if(left) delete left;
                if(right) delete right;
            }
        };

        TreeNode* CreateTreeBFS(vector<int> v){
            TreeNode *root = nullptr, *ptr = nullptr;
            bool bSkipped = false;

            queue<int> q;
            for(auto n : v)
                q.push(n);

            while(!q.empty()){
                if(root == nullptr) {
                    root = new TreeNode(q.front());
                    ptr = root;
                }
                else{
                    int next_val = q.front();
                    if (!bSkipped && ptr->left == nullptr) {
                        if ( next_val == 0)
                            bSkipped = true;
                        else
                            ptr->left = new TreeNode(next_val);
                    }
                    else if (ptr->right == nullptr) {
                        if (next_val != 0)
                            ptr->right = new TreeNode(next_val);
                    }
                }
                q.pop();
            }
            return root;
        }
#endif // __EVERYTHING__H
