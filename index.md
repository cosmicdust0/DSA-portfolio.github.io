# Supply Chain Optimization with DSA

<dl>
<dt>Course Name</dt>
<dd>Algorithmic Problem Solving</dd>
<dt>Course Code</dt>
<dd>23ECSE309</dd>
<dt>Name</dt>
<dd>Ravishankar S Bevinal</dd>
<dt>University</dt>
<dd>KLE Technological University, Hubballi-31</dd>
</dl>

# Project Description:
This project demonstrates the application of data structures and algorithms (DSA) and ML to optimize a specific aspect of supply chain management, such as inventory management, logistics planning, or route optimization. 

### Contents 
1. [Goals](#Goals)
2. [Business Use Cases](#BusinessUseCases)

# Goals<a name="Goals"></a>
## Skills Development
* **Data Structures and Algorithms (DSA) Proficiency:**
  -Apply efficient data structures (e.g., graphs, queues, trees) and algorithms (e.g., sorting, searching, shortest path) to solve complex supply chain problems.
  
* **Problem-Solving Expertise:**
  - Develop innovative solutions using appropriate DSA knowledge, demonstrating critical thinking and problem-solving skills.
* **Algorithmic Optimization:**
  - Showcase an understanding of algorithm complexity and the ability to tailor them for specific supply chain requirements.
* **Effective Data Management:**
  - Employ strong data handling skills, including data organization, manipulation, and analysis using efficient techniques.
  
## Career Advancement
* **Recognise and Understand the domain of my interest:**
 -Research different fields that seem aligned with my self-reflection. Read about careers, watch videos, and talk to seniors/professionals in these areas of SCM.
  
* **Enhanced Engineering Capabilities:**
  - Build robust and efficient supply chain systems using DSA, elevating my engineering skillset.
  - Demonstrate proficiency in applying computer science concepts to tackle real-world supply chain problems.
* **Portfolio Impact:**
  - Create a strong portfolio showcasing innovative projects that address real-world supply chain problems using DSA.
  - Impress potential employers with my ability to design and implement effective solutions, making you a strong candidate for roles in supply chain management and software development.

# Business Use Cases<a name="BusinessUseCases"></a>

1. [Route Optimization for Last-Mile Delivery](#RouteOptimization)
2. [Inventory Optimization System](#InventoryOptimization)
3. [Supplier Performance Tracking System](#SupplierPerformance)
4. [Warehouse Layout Optimization](#WarehouseLayout)
5. [Demand Forecasting System](#DemandForecasting)
6. [Supply Chain Risk Management System](#RiskManagement)
7. [Multi-Echelon Inventory Optimization](#MultiEchelonInventory)
8. [Predictive Maintenance System](#PredictiveMaintenance)
9. [Collaborative Demand and Supply Planning](#CollaborativePlanning)
10. [Smart Contract Management System](#SmartContracts)
11. [Network Design Optimization](#NetworkDesign)
12. [Reverse Logistics Optimization](#ReverseLogistics)
13. [Dynamic Pricing Optimization](#DynamicPricing)
14. [Sustainable Supply Chain Management](#SustainableSupplyChain)
15. [Supply Chain Finance Optimization](#SupplyChainFinance)


## Route Optimization for Last-Mile Delivery<a name="RouteOptimization"></a>
**A system that calculates the most efficient routes for delivery vehicles, considering factors like traffic, delivery windows, and vehicle capacity.**


Description


- **Challenges**: Real-time route adjustments, handling dynamic traffic conditions, balancing multiple objectives (time, cost, customer satisfaction).
- **Market Benefits**: Reduced fuel costs, improved on-time deliveries, increased delivery capacity.
- **Design Techniques and Algorithms**:
  - **A* Search Algorithm**: For finding optimal routes.
    - **Time Complexity**: O(b^d), where b is the branching factor and d is the depth of the goal.
    - **Space Complexity**: O(b^d), for storing the open and closed lists.
  - **Ford-Fulkerson Algorithm**: For maximizing the flow of deliveries through the network.
    - **Time Complexity**: O(E * max_flow), where E is the number of edges in the graph.
    - **Space Complexity**: O(V), where V is the number of vertices in the graph.
![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/119f905d-bce9-4f49-afd3-7671d5162dc4)



Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/route_optimization.cpp)








[Back to contents](#BusinessUseCases)




## Inventory Optimization System<a name="InventoryOptimization"></a>
**An AI-driven system that predicts demand, optimizes stock levels, and automates reordering processes across multiple warehouses.**


Description


- **Challenges**: Handling variable lead times, accounting for seasonal fluctuations, integrating data from multiple sources.
- **Market Benefits**: Reduced carrying costs, minimized stockouts, improved cash flow.
- **Design Techniques and Algorithms**:
  - **Fenwick Tree (Binary Indexed Tree)**: For efficient range sum queries on historical sales data.
    - **Time Complexity**: O(log n) for update and query operations, where n is the number of data points.
    - **Space Complexity**: O(n), for storing the tree.
  - **Exponential Smoothing**: For time series forecasting.
    - **Time Complexity**: O(n), where n is the number of historical data points.
    - **Space Complexity**: O(1), as it only needs to store a few parameters.

![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/01f7a226-b78f-413f-b264-11764eb57520)



Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/inventory_optimization.cpp)







[Back to contents](#BusinessUseCases)


## Supplier Performance Tracking System<a name="SupplierPerformance"></a>
**A system that monitors, evaluates, and ranks supplier performance based on multiple criteria such as quality, on-time delivery, and cost.**


Description


- **Challenges**: Integrating diverse data sources, maintaining data accuracy, providing real-time insights.
- **Market Benefits**: Improved supplier relationships, reduced supply chain risks, better negotiation position.
- **Design Techniques and Algorithms**:
  - **Red-Black Trees**: For efficient insertion, deletion, and retrieval of supplier performance data.
    - **Time Complexity**: O(log n) for insert, delete, and search operations, where n is the number of suppliers.
    - **Space Complexity**: O(n), for storing the tree.
  - **Heap**: For maintaining a priority queue of suppliers based on performance scores.
    - **Time Complexity**: O(log n) for insert and delete-max operations, where n is the number of suppliers.
    - **Space Complexity**: O(n), for storing the heap.




Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/supplier_performance.cpp)







[Back to contents](#BusinessUseCases)


## Warehouse Layout Optimization<a name="WarehouseLayout"></a>
**A system that optimizes the placement of goods within a warehouse to minimize picking time and improve overall efficiency.**


Description


- **Challenges**: Handling frequently changing inventory, accommodating various item sizes and storage requirements, and optimizing for multiple objectives (e.g., picking efficiency, space utilization).
- **Market Benefits**: Increased warehouse productivity, reduced operational costs, improved order fulfilment speed.
- **Design Techniques and Algorithms**:
  - **KD Tree**: For efficient spatial partitioning and nearest neighbour searches.
    - **Time Complexity**: O(log n) for search operations on average, where n is the number of items.
    - **Space Complexity**: O(n), for storing the tree.
  - **Genetic Algorithm**: For evolving optimal layout solutions.
    - **Time Complexity**: O(g * p * f), where g is the number of generations, p is the population size, and f is the cost of fitness evaluation.
    - **Space Complexity**: O(p), for storing the population.


![Screenshot 2024-07-07 194128](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/2196954c-f9cd-4db3-8e0b-fd80b67b7973)


Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/warehouse_layout.cpp)





[Back to contents](#BusinessUseCases)




## Demand Forecasting System<a name="DemandForecasting"></a>


Description

**An advanced analytics system that predicts future demand for products based on historical data, market trends, and external factors.**

- **Challenges**: Handling seasonality, incorporating external factors (e.g., economic indicators, weather), and dealing with new product introductions.
- **Market Benefits**: Improved inventory management, better production planning, reduced stockouts and overstocks.
- **Design Techniques and Algorithms**:
  - **Segment Trees**: For efficient range queries on historical sales data.
    - **Time Complexity**: O(log n) for range query and update operations, where n is the number of data points.
    - **Space Complexity**: O(n), for storing the tree.
  - **MO's Algorithm**: For efficiently answering multiple range queries offline.
    - **Time Complexity**: O((n+q) * √n), where n is the number of data points and q is the number of queries.
    - **Space Complexity**: O(n), for storing the input array and query results.
![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/92ef5433-3853-47b7-a0e7-c9987357870a)




Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/demand_forecasting.cpp)






[Back to contents](#BusinessUseCases)



## Supply Chain Risk Management System<a name="RiskManagement"></a>


Description

**A system that identifies, assesses, and mitigates risks across the supply chain, including supplier failures, geopolitical events, and natural disasters.**

- **Challenges**: Integrating diverse risk factors, quantifying risk impacts, providing actionable mitigation strategies.
- **Market Benefits**: Improved supply chain resilience, reduced disruptions, better strategic decision-making.
- **Design Techniques and Algorithms**:
  - **DFS (Depth-First Search)**: For analyzing supply chain dependency graphs.
    - **Time Complexity**: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
    - **Space Complexity**: O(V), for the recursion stack.
  - **Monte Carlo Simulation**: For risk assessment and scenario analysis.
    - **Time Complexity**: O(n * s), where n is the number of risk factors and s is the number of simulations.
    - **Space Complexity**: O(n), for storing simulation results.


![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/8f173158-6562-4b37-aff1-e6a2279088af)


Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/risk_management.cpp)






[Back to contents](#BusinessUseCases)



## Multi-Echelon Inventory Optimization<a name="MultiEchelonInventory"></a>


Description

**A system that optimizes inventory levels across multiple tiers of the supply chain, from raw materials to finished goods.**

- **Challenges**: Coordinating inventory decisions across multiple parties, handling varying lead times and demand patterns, balancing service levels and costs.
- **Market Benefits**: Reduced overall inventory costs, improved service levels, enhanced supply chain visibility.
- **Design Techniques and Algorithms**:
  - **Dynamic Programming**: For optimizing inventory decisions across time periods and echelons.
    - **Time Complexity**: O(n * m * k), where n is the number of time periods, m is the number of echelons, and k is the number of possible inventory levels.
    - **Space Complexity**: O(n * m * k), for storing the dynamic programming table.
  - **Square Root Decomposition**: For efficiently handling range queries and updates on inventory data.
    - **Time Complexity**: O(√n) for query and update operations, where n is the number of inventory items.
    - **Space Complexity**: O(n), for storing the decomposed array.




Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/multi_echelon_inventory.cpp)







[Back to contents](#BusinessUseCases)


## Predictive Maintenance System<a name="PredictiveMaintenance"></a>


Description

**An IoT-based system that monitors equipment health in real-time and predicts maintenance needs to prevent breakdowns and optimize maintenance schedules.**

- **Challenges**: Integrating data from diverse sensors, developing accurate predictive models, balancing maintenance costs with downtime risks.
- **Market Benefits**: Reduced equipment downtime, lower maintenance costs, extended equipment lifespan.
- **Design Techniques and Algorithms**:
  - **Random Forest**: For predictive modeling of equipment failures.
    - **Time Complexity**: O(n * log(n) * m * k), where n is the number of samples, m is the number of features, and k is the number of trees.
    - **Space Complexity**: O(m * k), for storing the forest.
  - **Trie**: For efficient storage and retrieval of equipment maintenance histories.
    - **Time Complexity**: O(k) for insert and search operations, where k is the length of the key.
    - **Space Complexity**: O(n * k), where n is the number of keys and k is the average key length.

![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/559d2b15-1e20-425d-a068-b97d81004901)



Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/predictive_maintenance.cpp)






[Back to contents](#BusinessUseCases)



## Collaborative Demand and Supply Planning<a name="CollaborativePlanning"></a>


Description

**A platform that enables real-time collaboration between suppliers, manufacturers, and retailers to align demand forecasts with supply plans.**

- **Challenges**: Ensuring data consistency across parties, handling conflicting objectives, providing real-time visibility and decision support.
- **Market Benefits**: Reduced bullwhip effect, improved forecast accuracy, enhanced supply chain agility.
- **Design Techniques and Algorithms**:
  - **Consensus Algorithm**: For reaching agreement on shared forecasts.
    - **Time Complexity**: O(n * r), where n is the number of participants and r is the number of rounds.
    - **Space Complexity**: O(n), for storing participant states.
  - **B-Tree**: For efficient storage and retrieval of large volumes of planning data.
    - **Time Complexity**: O(log n) for search, insert, and delete operations, where n is the number of keys.
    - **Space Complexity**: O(n), for storing the tree.

![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/6cf26b08-760c-454f-9d1d-faf58bc6b2e8)



Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/collaborative_planning.cpp)






[Back to contents](#BusinessUseCases)



## Smart Contract Management System<a name="SmartContracts"></a>


Description

**A blockchain-based system that automates contract execution, payments, and compliance monitoring across the supply chain.**

- **Challenges**: Ensuring contract security and privacy, integrating with legacy systems, handling complex contract logic.
- **Market Benefits**: Reduced transaction costs, improved contract compliance, increased trust among supply chain partners.
- **Design Techniques and Algorithms**:
  - **Merkle Trees**: For efficient verification of blockchain transactions.
    - **Time Complexity**: O(log n) for proof generation and verification, where n is the number of transactions.
    - **Space Complexity**: O(n), for storing the tree.
  - **State Machine**: For modeling and executing smart contract logic.
    - **Time Complexity**: O(1) for state transitions.
    - **Space Complexity**: O(s), where s is the number of possible states.

![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/8a017d61-0526-4a76-9ebb-0d5c2e79ed77)



Code Implementation

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/smart_contracts.cpp)






[Back to contents](#BusinessUseCases)



## Network Design Optimization<a name="NetworkDesign"></a>


Description

**A system that optimizes the design of the supply chain network, including the location and capacity of facilities, transportation links, and inventory placement.**

* **Challenges**: Handling complex constraints, balancing multiple objectives (cost, service level, risk), incorporating future scenarios.
* **Market Benefits**: Reduced overall supply chain costs, improved service levels, enhanced strategic decision-making.
* **Design Techniques and Algorithms**:
   * **Boruvka's Algorithm**: For finding the minimum spanning tree in the supply chain network.
      * **Time Complexity**: O(E log V), where E is the number of edges and V is the number of vertices.
      * **Space Complexity**: O(E + V), for storing the graph and MST.
   * **Integer Programming**: For solving complex network design optimization problems.
      * **Time Complexity**: Exponential in the worst case, but often practical for real-world problems with modern solvers.
      * **Space Complexity**: O(n * m), where n is the number of variables and m is the number of constraints.
![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/9e4ec691-f6c5-4ece-b487-052eff790084)




Code Implementation

**Here is sample code:**

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/network_design.cpp)







[Back to contents](#BusinessUseCases)


## Reverse Logistics Optimization<a name="ReverseLogistics"></a>


Description

**A system that optimizes the collection, processing, and disposition of returned goods, minimizing costs and maximizing value recovery.**

* **Challenges**: Handling unpredictable return volumes and conditions, optimizing disposition decisions, integrating with forward logistics.
* **Market Benefits**: Reduced reverse logistics costs, improved customer satisfaction, increased value recovery from returns.
* **Design Techniques and Algorithms**:
   * **K-Means Clustering**: For grouping return locations and optimizing collection routes.
      * **Time Complexity**: O(n * k * i), where n is the number of points, k is the number of clusters, and i is the number of iterations.
      * **Space Complexity**: O(n + k), for storing point assignments and centroids.
   * **Decision Trees**: For automating disposition decisions based on product condition and market factors.
      * **Time Complexity**: O(n * log(n)) for training, where n is the number of samples.
      * **Space Complexity**: O(m), where m is the number of nodes in the tree.


![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/3fb6bc84-83ac-4b88-ba8d-d472b57466be)


Code Implementation

**Here is sample code:**

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/reverse_logistics.cpp)







[Back to contents](#BusinessUseCases)


## Dynamic Pricing Optimization<a name="DynamicPricing"></a>


Description

**A system that adjusts product prices in real-time based on demand, inventory levels, competitor pricing, and other market factors.**

* **Challenges**: Handling real-time data streams, balancing multiple pricing objectives, ensuring pricing consistency across channels.
* **Market Benefits**: Increased revenue and profit margins, improved inventory turnover, enhanced competitive positioning.
* **Design Techniques and Algorithms**:
   * **Reinforcement Learning**: For optimizing pricing decisions over time.
      * **Time Complexity**: O(s * a * e), where s is the number of states, a is the number of actions, and e is the number of episodes.
      * **Space Complexity**: O(s * a), for storing the Q-table.
   * **AVL Trees**: For maintaining sorted price lists with efficient updates.
      * **Time Complexity**: O(log n) for insert, delete, and search operations, where n is the number of prices.
      * **Space Complexity**: O(n), for storing the tree.


![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/6e88da94-48b8-497b-a07c-7b07f53b3a20)


Code Implementation

**Here is sample code:**

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/dynamic_pricing.cpp)






[Back to contents](#BusinessUseCases)



## Sustainable Supply Chain Management<a name="SustainableSupplyChain"></a>


Description

**A system that monitors, reports, and optimizes the environmental and social impact of supply chain operations, including carbon emissions, water usage, and fair labor practices.**

* **Challenges**: Collecting accurate sustainability data, quantifying and optimizing multiple sustainability metrics, ensuring compliance with diverse regulations.
* **Market Benefits**: Improved brand reputation, compliance with regulations, reduced environmental impact and associated costs.
* **Design Techniques and Algorithms**:
   * **Multi-Objective Optimization**: For balancing economic, environmental, and social objectives.
      * **Time Complexity**: O(n * m * g), where n is the population size, m is the number of objectives, and g is the number of generations.
      * **Space Complexity**: O(n * m), for storing the population and Pareto front.
   * **Radix Tree**: For efficient storage and retrieval of hierarchical sustainability data.
      * **Time Complexity**: O(k) for insert and search operations, where k is the length of the key.
      * **Space Complexity**: O(n * k), where n is the number of keys and k is the average key length.




Code Implementation

**Here is sample code:**

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/sustainable_supply_chain.cpp)






[Back to contents](#BusinessUseCases)



## Supply Chain Finance Optimization<a name="SupplyChainFinance"></a>


Description

**A system that optimizes working capital across the supply chain through techniques such as dynamic discounting, reverse factoring, and inventory financing.**

* **Challenges**: Assessing creditworthiness in real-time, optimizing payment terms across multiple parties, managing financial risks.
* **Market Benefits**: Improved cash flow for all parties, reduced financing costs, strengthened supplier relationships.
* **Design Techniques and Algorithms**:
   * **Network Flow Algorithms**: For optimizing cash flows across the supply chain network.
      * **Time Complexity**: O(V * E^2) for Edmonds-Karp algorithm, where V is the number of vertices and E is the number of edges.
      * **Space Complexity**: O(V + E), for storing the residual graph.
   * **Skip List**: For maintaining sorted lists of invoices with efficient insertion and removal.
      * **Time Complexity**: O(log n) expected time for search, insert, and delete operations, where n is the number of elements.
      * **Space Complexity**: O(n), for storing the skip list.


![image](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/6f2b523f-dc27-469d-a3bf-89d01dcdcbdc)


Code Implementation

**Here is sample code:**

[GitHub Link to Code](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/c109011160512e2f39db670ca013749319527335/codes/supply_chain_finance.cpp)





[Back to contents](#BusinessUseCases)



