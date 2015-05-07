#include <cstdio>
#include <set>
#include <string>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <sys/stat.h>
using namespace std;
vector<string> getDataInInputFile(const string& fileName) {
    vector<string> ret;
    FILE *fp = fopen(fileName.c_str(),"r");
    char s[1024];

    while ( fgets(s,1024,fp) != NULL ) {
        while ( s[strlen(s)-1] == '\n' || s[strlen(s)-1] == '\r' ) 
            s[strlen(s)-1] = 0;
        ret.push_back(string(s));
    }
    fclose(fp);
    return ret;
}
inline bool isFileExists(const string& fileName) {
    struct stat buffer;
    return (stat(fileName.c_str(),&buffer) == 0);
}
vector<map<char,double> > getFrequencyInData(const vector<string>& data) {
    int dim = (int)data[0].length();
    vector<map<char,double> > ret;
    
    for ( int i = 0 ; i < dim ; i++ ) {
        map<char,double> freq;
        for ( int j = 0 ; j < (int)data.size() ; j++ ) 
            freq[data[j][i]] += 1.0f;
        for ( map<char,double>::iterator it=freq.begin();it!=freq.end();it++ ) 
            it->second /= (int)data.size();
        ret.push_back(freq);
    }
    return ret;
}
inline double GEH(const string& s1,const string& s2,vector<map<char,double> >& frequency) {
    double ret = 0.0f;
    int dim = (int)s1.length();
    for ( int i = 0 ; i < dim ; i++ ) {
        if ( s1[i] != s2[i] ) ret += 1.0f;
        else ret += (1.0f/(double)dim)*(1-frequency[i][s1[i]]);
    }
    return ret;
}
int main(int argc,char *argv[]) {
    assert(argc==2);
    string dataFileName = string(argv[1]);
    assert(isFileExists(dataFileName));
    
    vector<string> data = getDataInInputFile(dataFileName);
    vector<map<char,double> > frequency = getFrequencyInData(data);

    for ( int i = 0 ; i < (int)data.size() ; i++ ) 
        printf("[%s:%s]: %.7lf\n","AAAA",data[i].c_str(),GEH("AAAA",data[i],frequency));

    set<string> ties;
    for ( int i = 0 ; i < (int)data.size() ; i++ ) 
        if ( GEH("AAAA",data[i],frequency) == 3.1875f ) {
            printf("[%s:%s]: %.7lf\n","AAAA",data[i].c_str(),3.1875);
            ties.insert(data[i]);
        }
    puts("");
    for ( auto it=ties.begin();it!=ties.end();it++ ) 
        for ( auto it1=ties.begin();it1!=ties.end();it1++ ) 
            if ( it1 != it ) 
                printf("[%s:%s]: %.7lf\n",(*it).c_str(),(*it1).c_str(),GEH(*it,*it1,frequency));
    /*
    while ( true ) {
        char s1[1024],s2[1024];
        scanf("%s %s",s1,s2);
        printf("[%s:%s]: %.7lf\n",s1,s2,GEH(s1,s2,frequency));
    }
*/
    return 0;
}
