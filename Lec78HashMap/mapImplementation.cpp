#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
  unordered_map<string, int> unorderedMap;
  // Insertion
  unorderedMap["Prabhjeet"] = 1;
  unorderedMap["Singh"] = 2;
  unorderedMap["Sandhu"] = 3;

  // Searching
  cout << "Searching:-\n";
  cout << unorderedMap["Prabhjeet"] << endl;
  cout << unorderedMap.at("Singh") << endl;
  cout << unorderedMap["Sandhu"] << endl;

  cout << "Unknownkey is Present: " << unorderedMap.count("unknownKey") << endl;
  cout<< "Size : " << unorderedMap.size()<<endl;

  //  Traversal
  cout << "Auto traversal:-\n";
  for (auto i : unorderedMap)
  {
    cout << i.first << " " << i.second << endl;
  }
  cout<<endl << "Iterator Traversal:-\n";

  unordered_map<string, int>::iterator it = unorderedMap.begin();
  while(it != unorderedMap.end()){
    cout << it->first << " " << it->second << endl;
    it++;
  }
  cout << endl;
}