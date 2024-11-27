# C++ Module 08: Templated Containers, Iterators, and Algorithms  

## Overview  
This repository contains my work for Module 08 of the C++ curriculum, focusing on templates, STL containers, and algorithms. The module emphasizes creating reusable components, enhancing existing container functionality, and working with iterators. Each exercise builds on the foundations of efficient and modular C++ programming.  

## Exercises  

### **Exercise 00: Easy Find**  
This exercise introduces the use of templates to create a function called `easyfind`, which searches for a specific integer in a variety of STL containers. The function demonstrates the power of templates for writing generic, reusable code and highlights iterator usage for container traversal.  

---

### **Exercise 01: Span**  
The `Span` class is a custom container designed to store integers and compute the shortest and longest spans (differences) between elements. It supports adding elements individually or in bulk using iterators, ensuring versatility. Additionally, robust error handling is implemented for invalid operations, such as attempting calculations with insufficient data.  

---

### **Exercise 02: MutantStack**  
The `MutantStack` class extends `std::stack` to make it iterable, bridging the gap between the stack’s LIFO structure and the accessibility of sequential containers like `std::list`. This exercise demonstrates how container adapters can be customized while retaining their original behavior.  

**Takeaways:**  
- Enhanced the functionality of `std::stack` using inheritance and iterators.  
- Defined custom iterators for a container.  
- Compared implementations with equivalent STL containers, such as `std::list`.  
- Explored the mechanics of container adapters in the STL.  

---

## Reflections  
This module provided hands-on experience with templates, iterators, and STL components, reinforcing their importance in writing efficient and modular C++ code. Each exercise demonstrated practical ways to solve common programming challenges, showcasing the versatility and power of the STL. The work completed here reflects a solid understanding of how to leverage these tools effectively for both general-purpose and specialized use cases.

