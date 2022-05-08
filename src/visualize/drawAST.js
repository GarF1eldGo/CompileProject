width = 1000;
height = 1000;



var tree = d3.layout.tree()
  .size([width, height-200])
  .separation(function(a, b) { return (a.parent == b.parent ? 1 : 2); });



d3.json("city_tree.json", function(error, root) {

    var nodes = tree.nodes(root);
    var links = tree.links(nodes);
  
    console.log(nodes);
    console.log(links);
  
});