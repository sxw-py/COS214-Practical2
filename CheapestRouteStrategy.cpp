#include "CheapestRouteStrategy.h"
#include <map>


std::vector<Place*> CheapestRouteStrategy::getRoute(Place* start, Place* end) {
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

    while(!unvisited.empty()){
        double minDist = 0.0;
        Place* current = nullptr;
        std::size_t minIndex = 0;
        bool first = true;

        for (std::size_t i =0; i<unvisited.size(); i++){
            Place* p = unvisited[i];
            if (!visited[p] && dist.find(p) != dist.end()){
                if (first || dist[p] < minDist){
                    minDist = dist[p];
                    current = p;
                    minIndex = i;
                    first = false;
                }
            }
        }

        if (current == nullptr){
            break;
        }

        unvisited.erase(unvisited.begin() + minIndex);
        visited[current] = true;

        if (current == end){
            std::vector<Place*> path;
            Place* node = end;
            while (node != nullptr){
                path.insert(path.begin(), node);
                node = parent[node];
            }
            return path;
        }

        std::vector<Place*> neighbours = current->getNeighbours();
        for (Place* neighbour : neighbours){
            if (!visited[neighbour]){
                double cost = current->getCostTo(neighbour);
                double newDist = dist[current] + cost;
                if (dist.find(neighbour) == dist.end() || newDist < dist[neighbour]){
                    dist[neighbour] = newDist;
                    parent[neighbour] = current;

                    bool found = false;
                    for (Place* p : unvisited){
                        if (p== neighbour){
                            found = true;
                            break;
                        }
                    }
                    if (!found){
                        unvisited.push_back(neighbour);
                    }
                }
            }
        }
    }
    return {};
   //has same implementation to shortest route but uses getCostTo
}