# ARC cache
Hi, user! This is my ARC cache. Let me tell you about it. 

ARC (Adaptive Replacement Cache) is a combination of LRU (Last Recently Used) and LFU (Last Frequently used) caches.
It is called Adaptive Replacement Cache, because it can split cache memory between LFU and LRU depending on what type of cache is more neccesarry in a moment.
So when LFU has not enough memory it takes this memory from LRU and vice versa. LFU has bigger priority, then LRU. It means that, firstly, new element is placed 
in LRU, and when we hit at him, he is being replaced to LFU. 

To test my ARC on your computer you should make 3 simple steps:
1) Clone this repository
2) Enter "make" in your console
3) Launch file "run"

To see graphic vizualization of ARC, you can open graph.dot with Graphviz or special extesion for .dot files in Visual Studio Code.
It's really amusing to watch this in real time.

So, I whish you like it. You can also look for another interesting projects in my profile.
Have a nice day or night! ( ˙꒳˙ )
