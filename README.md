# GQLlite  

[![Join the chat at https://gitter.im/webbery/gqlite](https://badges.gitter.im/webbery/gqlite.svg)](https://gitter.im/webbery/gqlite?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

This is the expriments for testing boundery of graph database in embedding device.  
## Designed

## Create Graph
```
{
    create: 'graph',
    in: 'memory'/'disk'     // default is disk
}
```
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
        ['Tom', {'->': 'son'}, 'Jimmy'],
        ['Kitty', {'<-': 'wife'}, 'Jimmy'],
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
    '->': 'son',
    in: 'graph'
}
```
```
{
    query: '*',
    from: 'vertex',
    start: 'p',
    '->': 'friend',
    where: [
        {vertex: function(vertex) { return vertex.age > 10}}
    ],
    in: 'graph'
}
```
query a list of vertex from p1 to p2, with condition defined by function:
```
{
    query: '*',
    from: 'vertex',
    start: 'p1',
    end: 'p2',
    '--': 'friend',
    where: [
        {'--': function(left, relation, right) { return relation.weight > 0.75}}
    ],
    in: 'graph'
}
```
## Inference
Here we define a kind of inference operator, and apply it to a graph.  
First Order Logic:
```
{
    infer: '*',
    start: 'p',
    in: 'graph',
    define: function reverse(relation) { return 'father'}
}
```
HMM:
```
{
    infer: '*',
    start: ['p1', 'p2', 'p3'],
    in: 'graph',
    '->': function(from, to) {return 0.5;}
}
```
## Ceate Job
## Transition