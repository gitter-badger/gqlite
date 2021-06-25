/*
 add vertex:
 {
    add: graph,
    vertex:[
        ['Tom', {'age': 10}],
        ['Kitty', {'sex': 'female'}],
        ['Jimmy', {'sex': 'male', 'age': 35}]
    ]
}

add edge:
{
    add: graph,
    edge: [
        ['Tom', {'relation': 'son', from: 'Tom', to: 'Jimmy'}, 'Jimmy'],
        ['Kitty', {'relation': 'wife', from: 'Kitty', to: 'Jimmy'}, 'Jimmy'],
    ]
}
-- group feature
load from file(for script)
query:
{
    query: graph,
    where: [
        {relation: 'son'}
    ]
}
clear()
delete edge:
{
    remove: graph,
    edge: [
        ['Tom', {'relation': 'son', from: 'Tom', to: 'Jimmy'}, 'Jimmy']
    ]
}
delete vertex:
{
    remove: graph,
    vertex: [
        'Tom'
    ]
}
update vertex:
update edge:
begin():
commit():
extract to script:
*/
#include "../include/gqlite.h"

int main() {
    gqlite* pHandle = 0;
    gqlite_open("test", &pHandle);
    gqlite_close(pHandle);
}