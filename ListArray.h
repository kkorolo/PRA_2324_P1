#include <ostream>
#include "List.h"
using namespace std;
template <typename T>
class ListArray : public List<T> {
    private:
        T* arr;
        int max;
        int n;
        static const int MINSIZE = 2;
    public:
        ListArray();
        ~ListArray();

        void resize (int new_size){
			T* new_arr = new T[new_size];
			for(int i=0;i<n;i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			T* arr = new_arr;
			max = new_size;
		}
        int size(){
			return n;
		}
        void insert(int pos, T element){
			if(pos<0||pos>size()-1){
				throw out_of_range("Posicion no valida");
			}
			n++;
			if(n>max){
				resize(n+1);
			}
			for(int i=n;i>=pos;i--){
			arr[i]=arr[i-1];
			}
			arr[pos] = element;
		}
        void append(T element){
			insert(n, element);
		}

        void prepend(T element){
			insert(0, element);
		}
        T remove(int pos){
			if(pos<0||pos>size()-1){	
				throw out_of_range("Posicion no valida");
			}
			int aux = arr[pos];
			for(int i=pos;i<n;i++){
				arr[i] = arr[i+1];
			}
			return aux;
		}
        T get(int pos){
			if(pos<0 || pos>size()-1){
				throw out_of_range("Posicion no valida");
			}
			return arr[pos];
		}
        T operator[](int pos){
			return get(pos);
        }
        bool empty(){
		    if(n!=0){
		       		return true;
		 	}
            else{
                return false;
            }
		}
        friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out<<"List --> [";
			for(int i=0; i<list.n;i++){
				out<<list.arr[i];
			}
			out<<"]\n";
			return out;
		}
        int search(T element){
			for(int i=0;i<n;i++){
				if(arr[i]==element){
					return i;
				}
			}
			return -1;
		}
};