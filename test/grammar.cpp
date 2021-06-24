/*
 add vertex:
[
    ['Tom', {'age': 10}],
    ['Kitty', {'sex': 'female'}],
    ['Jimmy', {'sex': 'male', 'age': 35}]
]
add edge:
    [
        ['Tom', {'relation': 'son'}, 'Jimmy'],
        ['Kitty', {'relation': 'wife'}, 'Jimmy'],
    ]
load from file(for script)
query:
clear()
delete edge:
delete vertex:
update vertex:
update edge:
begin():
commit():
extract to script:
*/
#include "../include/GQLlite.h"

int main() {
    gqlite* pHandle = 0;
    gqlite_open("test", &pHandle);
}