# Bloom Filter  

Bloom filters are powerful probabilistic data structure to detect the present of an element on a given set. On core, it is an array of bits.  

A bloom filter can predict absence of an item with 100% surity. However, sometimes it results into false positives. The % of false positives depends on the value of other parameters to be discussed below.  

---

## Properties of a Bloom Filter  

There are 4 key properties to construct a probabilistic bloom filter:  

- **n** = number of items  
- **m** = number of bits  
- **k** = number of hash functions  
- **p** = probablity of false positives  

The probability of a false positive in a Bloom filter is given by:  

$P_{fp} = \left(1 - e^{-\frac{k n}{m}}\right)^k$ 

### Few Observations  

- for constant *m* & *k*, as *n* increases, value of *p* also increases.  
- for constant *n* & *k*, as *m* increases, value of *p* decreases.  

---

## Bloom Filter Operations  

### Adding an Item  
When we add an item to a bloom filter, it runs a series of predefined hash functions on the given item to generate some unique numbers.  
Let's call them i1, i2, i3, … etc.  

Now, we take the modulo of each number wrt *m* (number of bits). Based on the result, the corresponding bit is turned on in the bloom filter source bit array.  

---

### Searching an Item  
When we search for an element in a bloom filter, it runs the same series of hahs function to generate the unique numbers and take their modulo wrt *m*.  
Let's call them mi1, mi2, mi3, … etc.  

Since the hash functions are predictive for a particular input, in case we have encountered the input before, the corresponding bits at mi1, mi2, mi3, … are bound to be turned on in the bloom filter array. If any bit is off, we mark the input as absent.  

However, the same bits might be turned on by some other input, and that's the reason we sometimes encounter false positives in bloom filters.  

## Resources
- [Bloom Filters Part 1: An Introduction](https://commons.apache.org/proper/commons-collections/bloomFilters/intro.html)
- [Bloom Filter Calculator](https://hur.st/bloomfilter/)
- [Comparing Hash Algorithms](https://softwareengineering.stackexchange.com/a/145633)