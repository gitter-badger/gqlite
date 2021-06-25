# GQLlite

## Create Graph

## Add Vertex & Edge
add vertex:
```
{
    add: 'graph',
    vertex:[
        ['Tom', {'age': 10}],
        ['Kitty', {'sex': 'female'}],
        ['Jimmy', {'sex': 'male', 'age': 35}]
    ]
}
```
add edge:
```
{
    add: 'graph',
    edge: [
        ['Tom', {'relation': 'son', from: 'Tom', to: 'Jimmy'}, 'Jimmy'],
        ['Kitty', {'relation': 'wife', from: 'Kitty', to: 'Jimmy'}, 'Jimmy'],
    ]
}
```
## Query
### embeded function
#### count()
```
{
    query: count(),
    from: 'vertex'
}
```
### condition
```
{
    query: ['sex', 'age'],
    from: 'vertex',
    where: [
        {relation: 'son'}
    ],
    in: 'graph'
}
```
```
{
    query: ['sex', 'age'],
    from: 'vertex',
    where: [
        {age: {$gt: 20}}
    ],
    in: 'graph'
}
```
```
{
    query: '*',
    from: 'vertex',
    start: 'p',
    relation: 'son',
    in: 'graph'
}
```
```
{
    query: '*',
    from: 'vertex',
    start: 'p',
    relation: 'friend',
    where: [
        {vertex: function(vertex) { return vertex.age > 10}}
    ],
    in: 'graph'
}
```
{
    query: '*',
    from: 'vertex',
    start: 'p',
    relation: 'friend',
    where: [
        {relation: function(relation) { return relation.weight > 0.75}}
    ],
    in: 'graph'
}
```
## Ceate Job

## Transition