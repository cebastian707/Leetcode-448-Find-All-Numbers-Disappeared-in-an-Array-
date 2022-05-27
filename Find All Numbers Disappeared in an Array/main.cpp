/*By::Cebastian Santiago 
* Leetcode 448
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
	//sort the vector
	std::sort(nums.begin(), nums.end());

	//variables 
	std::vector<int> temp;
	std::set<int> sets;
	int low = 1;
	int right = nums.size() - 1;
	int high = nums[right];

	//insert elements into the set
	for (size_t i = 0; i < nums.size(); i++) {
		sets.insert(nums[i]);
	}


	//check for the value one
	auto it = sets.find(1);

	if (it == sets.end()){
		temp.push_back(1);
	}


	//while low less then right
	while (low <= right){
		//compare the number
		low += 1;

		auto it = sets.find(low);

		if (it == sets.end()){
			temp.push_back(low);
		}

	}
	return temp;
}


int main(int argv , char argc[]) {
	std::vector<int> nums = { 5,4,6,7,9,3,10,9,5,6 };

	std::vector<int> an = findDisappearedNumbers(nums);


	for (size_t i = 0; i < an.size(); i++) {
		std::cout << an[i] << std::endl;
	}


}