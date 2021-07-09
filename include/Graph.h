#pragma once
#include <mdbx.h++>
#include <vector>

typedef uint32_t EdgeID;
typedef uint32_t VertexID;

template<int Kind>
struct Link
{
    VertexID _id;
    uint16_t _lcnt;      // link count
    EdgeID* _links;
    double _weight;
};

typedef Link<1> Vertex;
typedef Link<2> Edge;
typedef Link<3> Group;

struct VertexDegree {
    VertexID _maxInID;
    VertexID _maxOutID;
};

struct GraphProperty {
    union {
        VertexID _maxDegreeID;
        VertexDegree _maxID;
    };
    uint32_t _vertexCount;
    uint32_t _edgeCount;
};

class GGraph {
public:
    GGraph();
    ~GGraph();

    std::vector<Edge> getEdges();
    std::vector<Edge> getEdges(VertexID vertex);
    std::vector<Vertex> getVertex();
    std::vector<Vertex> getVertex(EdgeID edge);

    int addVertex(const std::string& name, const std::string& info, VertexID& outID);
    int addEdge(const std::string& name, const std::string& info, Edge& outID);

private:
    // a key-value map save links of vertex and edges
    mdbx::map_handle _handle;
    GraphProperty _property;
};