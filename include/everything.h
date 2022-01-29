#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <climits>
#include <ostream>
#include <algorithm>
#include <type_traits>
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
                ret += print_array(array) + ", ";
            return ret + "]" ;            
        }

        template <typename T>
        bool match_array(vector<T> array1, vector<T> array2){
            if (array1.size() != array2.size())
                return false;

            for(int i = 0; i< array1.size() ; i++){
                if(array1[i] != array2[i])
                    return false;
            }
            return true;
        }
        
        template <typename T>
        bool match_arrays_of_arrays(vector<vector<T>> arrayOfArrays1, vector<vector<T>> arrayOfArrays2){
            if (arrayOfArrays1.size() != arrayOfArrays2.size())
                return false;

            for(int i = 0; i< arrayOfArrays1.size() ; i++){
                if(match_array(arrayOfArrays1[i], arrayOfArrays2[i]))
                    return false;
            }
            return true;
        }
#endif // __EVERYTHING__H
