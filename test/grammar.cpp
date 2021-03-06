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

int gqlite_exec_callback(void* params )
{
    return 0;
}

int main() {
    gqlite* pHandle = 0;
    gqlite_open("gql_db", &pHandle);
    gqlite_exec(pHandle,
    "{\
        create: 'graph',\
        in: 'memory'\
    }", gqlite_exec_callback, nullptr);
    gqlite_exec(pHandle,
    "{\
        drop: 'graph'\
    }", gqlite_exec_callback, nullptr);
    gqlite_close(pHandle);
}