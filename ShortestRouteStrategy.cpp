#include "ShortestRouteStrategy.h"
#include <map>

std::vector<Place*> ShortestRouteStrategy::getRoute(Place* start, Place* end) {
    if (!start || !end){
        return {};
    }

    if (start == end){
        return {start};
    }
    
    std::map<Place*, double> dist; 
    std::map<Place*, Place*> parent;  
    std::map<Place*, bool> visited;  
    std::vector<Place*> unvisited;  

    dist[start] = 0.0;
    parent[start] = nullptr;
    unvisited.push_back(start);
   
    

    while (!unvisited.empty()){
        //find unvisited place with smallest known distance
        double minDist = 0.0;
        Place* current = nullptr;
        std::size_t minIndex = 0;
        bool first = true;

        for (std::size_t i = 0; i< unvisited.size(); i++){
            Place* p = unvisited[i];
            if (!visited[p] && (first || dist[p] < minDist)){
                minDist = dist[p];
                current = p;
                minIndex = i;
                first = false;
            }
        }

        if (current == nullptr){
            break;   //remaining places unreachable from start
        }

        unvisited.erase(unvisited.begin() + minIndex);

        if (visited[current]){
            continue;  
        }

        //got to destination with shortest distance finalised. parent pointers back at start
        if (current == end){
            std::vector<Place*> path;
            Place* node = end;
            while (node != nullptr){
                path.insert(path.begin(), node);
                node = parent[node];
            }
            return path;
        }

        //if reaching it via current is shorter, record improvement
        for (Place* neighbour : current->getNeighbours()){
            if (visited[neighbour]){
                continue;
            }
            double newDist = dist[current] + current->getDistanceTo(neighbour);
            if (dist.find(neighbour) == dist.end() || newDist < dist[neighbour]){
                dist[neighbour] = newDist;
                parent[neighbour] = current;
                unvisited.push_back(neighbour); 
            }
        }
    }
    return {};
}