typedef char*(*vertex_to_string)(Vertex);

void add_friend(Vertex to, Vertex from);
void strongly_connected_compnent(Vertex graph[], int nelem, vertex_to_string vts);