#include <iostream>
#include <string>


bool isPalindrome(const std::string data,bool isOdd){
	int mid(data.size()/2-1),left,right;
	if (isOdd){
		left = mid;
		right = left + 2;
		while (left >= 0 && right < data.size()){
			if (data[left] == data[right]){
				left--;
				right++;
			}
			else return false;		
		}
		return true;
	}else {
		left = mid;
		right = left + 1;
		while (left >= 0 && right < data.size()){
			if (data[left] == data[right]){
				left--;
				right++;
			}
			else return false;	
		}
		return true;
	}
}




bool isPalindrome(const int data){
	std::string data_str = std::to_string(data);
	return isPalindrome(data_str,data_str.size() % 2);

}


int main(){
	int input_number = 123121;
	std::cout << std::boolalpha << isPalindrome(input_number);
	return 0;
}