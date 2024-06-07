# Supply Chain Optimization with DSA
https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/e0c1b077-40b9-4395-95c0-9b47e41e1ae9

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
2. [DSA involved](#DSAinvolved)
3. [Technology Stack](#Technology_Stack)
4. [ Modules of a supply chain ](#Modules)
5. [Extra functionalities that I would like to improve/include ](#Functionalities)


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


 

# DSA involved<a name="DSAinvolved"></a>
This project utilizes various DSA techniques to enhance efficiency and decision-making in the supply chain. For example:

  * Graphs can represent the network of suppliers, warehouses, and distributors, enabling efficient route planning with algorithms like A*,  Dijkstra's algorithms etc.
  *  Hash maps, trees and queues can be used to model inventory flow, ensuring First-In-First-Out (FIFO) or other inventory management strategies.
  * Sorting algorithms can be applied to prioritize orders or shipments based on urgency, cost, or other criteria.

By incorporating DSA principles, my project aims to achieve significant improvements in  cost savings, delivery speed, and customer satisfaction.


# Technology Stack<a name="Technology_Stack"></a>

* Programming language(s): (e.g., Python, Javascript )
* Libraries/Frameworks: (e.g., Django, React )


## Modules of a supply chain <a name="Modules"></a>

This system comprises several interconnected modules for streamlined supply chain management:

**1. Raw materials Suppliers analysis and selection:**

* Manages supplier data (contact information, product catalogues, lead times, quality records).
* Enables searching and filtering suppliers based on various criteria.
* Supports supplier performance evaluation and risk assessments.
![photo_2024-06-07_23-43-38](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/0836c129-68b6-4b61-8d23-e780ecabc3b9)


**Supplier Selection:** The machine learning model will predict  the best supplier based on market trends to be selected every week, and then the info is fetched and the best route  to the supplier is calculated.

**Supplier info (Hash Table):**
Key: Unique Supplier ID (efficient to fetch)
Values:
Contact Information (Name, Address, Phone, Email)
Product Catalog (List of products offered with details)
Lead Time (Average time to fulfil an order)
Foreign Key to Quality Records Table (reference for detailed quality data)

**Information Retrieval:**
Use the supplier ID from the ML model output to directly access the main table in the hash table for quick retrieval of contact information, product catalogue, and lead time.

**Route Calculation:**
Algorithm: A* Search with a Priority Queue
This algorithm balances distance (heuristic) and actual travelled distance to find the fastest route.

**Implementation:**

* Create a graph data structure to store supplier locations and connecting routes.
* Define a heuristic function that estimates the remaining distance to the supplier's warehouse from the current location (e.g., straight-line distance).
* Use a priority queue to prioritize nodes based on a combination of the actual distance travelled and the heuristic estimate (total cost).
* Explore nodes in the priority queue, calculating the total cost (distance travelled + heuristic).
* Maintain a "closed list" of already visited nodes to avoid revisiting them.
* The algorithm terminates when the destination (supplier warehouse) is reached, returning the fastest route.
**Here is the explanation and the sample code:**
[ Raw materials Suppliers analysis and selection](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/be5e3a99e1c7355d1c9ac3430ebfd470b8077be8/Raw%20materials%20Suppliers%20analysis%20and%20selection)

**2. Economics/Finances of the complete product flow:**

* Handles cost calculations (raw materials, production, transportation, storage).
* Implements pricing models to optimize profitability.
* Analyzes economic trends and forecasts for informed decision-making.
* let us take an example of the beverage production
![photo_2024-06-07_23-43-27](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/008a7f3d-3da1-436e-8fc3-7c55741a6833)

### Beverage Production Cost Management System

This design of a system for managing beverage production costs, including ingredients, production costs, and marketing costs.

### Sub-Modules

The system consists of three main modules:

1. **Ingredients:**
    - **Data Structure:** Struct/Class representing an ingredient.
    - **Properties:**
        - Name (string)
        - Cost per unit (double)
        - Unit quantity needed per bottle (double)
    - **Storage:** Database
2. **Production Cost:**
    - **Data Structure:** Struct/Class (optional) or variable.
    - **Properties:**
        - Cost per unit of production (e.g., machinery operation, labor) (double)
    - **Storage:** Database
3. **Marketing Cost:**
    - **Data Structure:** `MarketingChannel` class and `MarketingChannelHeap` class.
    - **`MarketingChannel` Class:**
        - Properties:
            - Name (string)
            - Cost per reach (double)
            - Minimum reach (double)
            - Target audiences (optional: vector<string>)
            - Total cost (double) (calculated dynamically)
    - **`MarketingChannelHeap` Class:**
        - Min-heap implementation for efficient retrieval of the cheapest advertising option.
    - **Storage:** Database for channel details.

### Category Tree for Ingredients (Optional)

- A separate tree structure can be implemented (e.g., using a trie or a graph) to represent hierarchical relationships between ingredients (e.g., fruits, vegetables, grains).

### Implementation

**Ingredients:**

1. Store ingredient data (name, cost, unit quantity) in a database table.
2. Implement functions to add, edit, and delete ingredients.

**Production Cost:**

1. Store production cost per unit (machinery, labor) in a database table (optional: can be a single value).
2. Implement functions to update the production cost.

**Marketing Cost:**

1. Store marketing channel data (name, cost per reach, minimum reach, target audiences) in a database table.
2. Implement functions to add, edit, and delete marketing channels.
3. Use the `MarketingChannelHeap` to efficiently find the cheapest advertising option based on target audience and desired reach:
    - Populate the `MarketingChannelHeap` with channels from the database.
    - Calculate the total cost for each channel based on the desired reach.
    - Use the `extractCheapest` function of the `MarketingChannelHeap` to find the channel with the lowest total cost.



  
  **Here is the explanation and the sample code:**
  [Economics/Finances of the complete product flow](https://github.com/cosmicdust0/DSA-portfolio.github.io/tree/cc09a89ca8e91c833ee20bcc991d91f914c2ca08/EconomicsFinances%20of%20the%20complete%20product%20flow)

**3. Storage for raw materials  finished goods and other consumables:**

* Tracks inventory levels across various storage facilities.
* Optimizes inventory placement and allocation using appropriate data structures (e.g., graphs).
* Implements inventory management strategies (FIFO, LIFO, Just-in-Time).
![storage](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/1a960c8b-6c59-4499-bea0-dd585316175c)
![logistics](https://github.com/cosmicdust0/DSA-portfolio.github.io/assets/101003281/efd0f33c-2232-4ea2-bb5e-7e2a9e29f928)


## Functionalities that I would like to improve on <a name="Functionalities"></a>

This section will empower businesses with a range of functionalities to enhance supply chain performance:

**1. Analysis (Charts):**

* Generates insightful visualizations (charts, graphs) to represent key metrics (inventory levels, production costs, delivery times).
* Provides data analysis dashboards to monitor trends and identify areas for improvement.
* Uses data structures (e.g., trees) to facilitate efficient data organization and retrieval for visualization creation.


**2. Prediction(ML):**

* Integrates machine learning models or forecasting techniques to predict future demand, supply disruptions, and potential quality issues.
* Utilizes historical data (stored efficiently using data structures like arrays and linked lists) to train prediction models.
* Predictions enable proactive decision-making and inventory management.

**3. Management(frontend Dashboard):**

* Provides tools to manage suppliers, inventory, production schedules, quality control processes, and logistics operations.
* Integrates appropriate data structures and algorithms to support efficient management tasks (e.g., priority queues for order fulfilment).
* Streamlines supply chain operations for improved efficiency.

**4. Calculations:**

* Offers functionalities to calculate costs, delivery times, lead times, resource usage, and other relevant metrics.
* Leverages algorithms (e.g., dynamic programming for some calculations) to optimize performance and accuracy.
* Provides valuable insights for cost reduction and better resource allocation.





**Author:**

* Ravishankar Bevinal 

