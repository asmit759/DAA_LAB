import java.util.*;

class Pair {
    int vertex;
    int weight;
    Pair(int v, int w) {
        vertex = v;
        weight = w;
    }
}

class Solution {
    public int spanningTree(int V, List<List<List<Integer>>> adj) {
        // Min-heap based on edge weight
        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.weight - b.weight);
        
        boolean[] visited = new boolean[V];
        pq.add(new Pair(0, 0));  // Start from vertex 0
        int totalWeight = 0;
        
        while (!pq.isEmpty()) {
            Pair curr = pq.poll();
            int u = curr.vertex;
            
            // Skip if already part of MST
            if (visited[u]) continue;
            
            // Include this edge
            visited[u] = true;
            totalWeight += curr.weight;
            
            // Add all adjacent edges
            for (List<Integer> neighbor : adj.get(u)) {
                int v = neighbor.get(0);
                int wt = neighbor.get(1);
                if (!visited[v]) {
                    pq.add(new Pair(v, wt));
                }
            }
        }
        return totalWeight;
    }

    // Driver Code
    public static void main(String[] args) {
        int V = 5;
        int[][] edges = {
            {0, 1, 2},
            {0, 3, 6},
            {1, 2, 3},
            {1, 3, 8},
            {1, 4, 5},
            {2, 4, 7},
            {3, 4, 9}
        };
        
        // Build adjacency list
        List<List<List<Integer>>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        
        for (int[] e : edges) {
            adj.get(e[0]).add(Arrays.asList(e[1], e[2]));
            adj.get(e[1]).add(Arrays.asList(e[0], e[2]));
        }
        
        Solution sol = new Solution();
        int mstWeight = sol.spanningTree(V, adj);
        System.out.println("Total weight of MST: " + mstWeight);
    }
}
