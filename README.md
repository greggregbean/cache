# F&R cache
Hi, user! This is my F&R cache. Let me tell you about it. 

F&R is a combination of LRU (Last Recently Used) and LFU (Last Frequently used) caches.
It is called F&R, because it can split cache memory between LFU and LRU depending on what type of cache is more neccesarry in a moment. So when LFU has not enough memory it takes this memory from LRU and vice versa. LFU has bigger priority, then LRU. It means that, firstly, new element is placed in LRU, and when we hit at him, he is being replaced to LFU. 

If you want to build this project, you should clone this repositoryhen and enter "make" in console.
To test my cache just enter "./run" in console. 

If you want to see the work of cache in all details enter "./run detailed". In this mode you will see dump of cache in console
and graphic vizualization. To see graphic vizualization of F&Q, you can open graph.dot with Graphviz or special extesion for .dot files in Visual Studio Code. It's really amusing to watch this in real time.

So, I whish you like it. You can also look for another interesting projects in my profile.
Have a nice day or night! ( ˙꒳˙ )
