#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> box;
int dump, diff = 0;
int max_box = 0, min_box = 101;
int max_idx = 0, min_idx = 0;

int main() {
   ios::sync_with_stdio(0);
   cin.tie(0);

   for (int test_case = 1; test_case <= 10; test_case++) {
      cin >> dump;
      for (int i = 0; i < 100; i++) {
         int height;
         cin >> height;
         box.push_back(height);
      }
      for (int k = 0; k < dump; k++) {
         max_box = 0, min_box = 101;
         for (int j = 0; j < 100; j++) {
            if (max_box < box[j]) {
               max_box = box[j];
               max_idx = j;
            }
            if (min_box > box[j]) {
               min_box = box[j];
               min_idx = j;
            }
         }
         box[max_idx] = max_box - 1;
         box[min_idx] = min_box + 1;
		 diff = max_box - min_box;
		 if (diff <= 1) {
			 break;
		 }
      }
	  max_box = 0, min_box = 101;
	  for (int j = 0; j < 100; j++) {
		  max_box = *max_element(box.begin(), box.end());
		  min_box = *min_element(box.begin(), box.end());
	  }

      cout << "#" << test_case << " " << max_box - min_box << "\n";
      box.clear();
   }
}