#include "globaldefs.h"
#include "Results.h"

//the Results class holds the vector of maps from the last query
//and provides various ways to access them

//copy from the Query vector
Results::Results(vector <dbMap> crows) {
    rows.clear();
    for (int i = 0; i < crows.size(); i++) {
        rows.push_back(crows[i]);
    }
    cursor = 0;
}
Results::Results(vector <dbMap*>* prows) {
    rows.clear();
    //prows is a pointer to a vector
    //which contains pointers to dbMaps
    auto pvec = *prows;
    for (int i=0; i<pvec.size(); i++) {
       dbMap* pmap = pvec[i];
       rows.push_back(*pmap);
    }
};
vector<dbMap> Results::getRows() {
    return rows;
}
//get one row as a map
dbMap Results::getRow() {
    dbMap m = rows[cursor++];
    return m;
}
//get the value of the named column in the current row
//string Results::getVal(string name) {
mysqlx::Value Results::getVal(string name) {

    return rows[cursor][name];
}
//get the size of the result
size_t Results::getSize() {
    return rows.size();
}
void Results::setCursor(size_t cval) {
    cursor = cval;
}
//get the value of the map entry by index
string Results::getCol(int index) {
    if (cursor < rows.size()) {
        dbMap map = rows[cursor];
        auto it = map.begin();
        std::advance(it, index);
        mysqlx::Value v = it->second;
        return string(v);
    }
    else
        return "";
}

