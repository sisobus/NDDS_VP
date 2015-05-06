#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
vector<string> getDataInInputFile(char *fileName) {
    vector<string> ret;
    FILE *fp = fopen(fileName,"r");
    char s[1024];

    while ( fgets(s,1024,fp) != EOF ) {
        while ( s[strlen(s)-1] == '\n' || s[strlen(s)-1] == '\r' ) 
            s[strlen(s)-1] = 0;
        ret.push_back(string(s));
    }
    fclose(fp);
    return ret;
}
double GEH(string& s1,string& s2) {
}
int main(int argc,char *argv[]) {
    vector<string> vp;
    vector<string> data = getDataInInputFile("input");



    return 0;
}
