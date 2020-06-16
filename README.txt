My chosen solution was not intended to be my actual solution. I had originally intended to use Qwt to present the data by creating a tabbed GUI 
experience with each tab corresponding to some of the data. However, after 3.5 days of working with it, I realized it would take me longer than 
the 5 days I was given as my solution was a bit ambitious. 

Unfortunately, this meant scraping a large part of the work I had already done and starting over. To this end, I employed Plotly to help me with
the graphing portion and boost to help me with the reading of the data. Again, this wasnt my ideal solution but given the time constraints, I 
felt it was better to get something sort of working than nothing.

I've never worked with large datasets before, so exploring some of the issues associated with such a large volume was interesting, as was working
more with Qwt and Plotly. I've worked with them both, but never to this scale so it was a fun opportunity to dig into them more.

To improve my solution, I would have gotten Qwt working as I intended. I think this could have really been w great way to present the data to the 
users, unfortunately, I just ran out of time. There is some weird architecture in my final version that I would have liked to clean up, but trying 
to piece things together late in the game meant some technical debt was incurred. I originally intended to have an HTMLWriter class that would have
handled all the graph objects through polymorphism, but that didnt happen.

In terms of the graphs I did complete (BarGraph.html and MapGraph.html), I would have liked to incorporate more info into the map graph, ie: 
included the username and tweet of each location. I would also have liked to tie in the Facebook data as well.

My ambitious graph idea was to use the business information in the Facebook data, combined with the tweet locations and demographic info to create 
an estimate of the demographics of the area close to the businesses and close to the tweeters. I think this would have been particularly useful in the
real world, but time ran out.

In conclusion, I think I had a lot of great ideas that didnt quite come to fruition. Unfortunately, I can only be judged on what I present and not 
intentions. Please review the code and know this isnt where I would have liked it to be, but I appreciate your time and consideration throughout the process.
