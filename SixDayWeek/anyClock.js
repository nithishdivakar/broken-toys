var ANY_CLOCK=(function(){
/* ocnstants*/
	var pi = Math.PI;
	var time_zone_offset = (new Date).getTimezoneOffset()

/* private data members*/
	var svg, width, height, radius, bodyRadius, dotRadius;
	var root_elem;
	var division_per_dial;
	var bodyText;
	var fields;
	var color, offset_bla, arcBody, arcTextPath, g, body;
	var week_arc;

	var dial=[];

/*private function */
	dial.start=function(d,ind){
		return Math.floor(d/division_per_dial[ind])*division_per_dial[ind];
	}
	dial.offset=function(d,ind){
		return d+division_per_dial[ind];
	}
	dial.format=function(d,ind){
		offset = 0;
		if(ind ==4) offset = 4;
		return ""+(Math.floor((d-dial.start(d,ind))/division_per_dial[ind-1])+offset);
	}
	
	
	var init = function(id,time_div){
		root = document.getElementById(id.substring(1));
		width = root.offsetWidth;
		height = root.offsetHeight;
	
		svg = d3.select(id).append("svg:svg").style("width",width+"px").style("height",height+"px");
		radius = Math.min(width, height) / 1.9;
		bodyRadius = radius / 23;
		dotRadius = bodyRadius - 8;
	
		color = d3.scaleRainbow().domain([0, 360]);
	
		//time_div.push(1000);/* appending milliseconds*/
	
		division_per_dial =new Array(time_div.length)
		division_per_dial[0]=time_div[0];
		for( i =1;i<time_div.length;i++){
			division_per_dial[i] = division_per_dial[i-1]*time_div[i];
		}
		console.log(time_div);
		console.log(division_per_dial);
		/*
		console.log(time_div);
		console.log(division_per_dial);
		console.log(division_per_dial);
		*/
		fields = []
		for(i=0;i<time_div.length;i++){
			fields.push({index:i,radius:(i)*0.1*radius});
		}
	

		offset_bla = bodyRadius*60*pi/180;
		arcBody = d3.arc()
			.startAngle(function(d) { return bodyRadius / d.radius - offset_bla/d.radius; })
			.endAngle(function(d) { return -2*pi - bodyRadius / d.radius + offset_bla/d.radius; })
			.innerRadius(function(d) { return d.radius - bodyRadius; })
			.outerRadius(function(d) { return d.radius + bodyRadius; })
			;//.cornerRadius(bodyRadius);
		
		arcTextPath = d3.arc()
			.startAngle(function(d) { return -bodyRadius / d.radius ; })
			.endAngle(-pi)
			.innerRadius(function(d) { return d.radius; })
			.outerRadius(function(d) { return d.radius; });
		
		week_arc = d3.arc()
			.startAngle(function(d) { angle = 2*pi*(d.day*24+d.start)/(24*7); console.log(angle); return angle; })
			.endAngle(  function(d) { angle = 2*pi*(d.day*24+d.end  )/(24*7); console.log(angle); return angle; })
			.innerRadius(function(d) { return (time_div.length+1)*0.1*radius - bodyRadius; })
			.outerRadius(function(d) { return (time_div.length+1)*0.1*radius + bodyRadius; })
			;//.cornerRadius(bodyRadius);

		week_schedule=[
	/*		{"day":0,"start":0,"end":24,"type":"sleep"},
			{"day":1,"start":0,"end":24,"type":"sleep"},
			{"day":2,"start":0,"end":24,"type":"sleep"},
			{"day":3,"start":0,"end":24,"type":"sleep"},
			{"day":4,"start":0,"end":24,"type":"sleep"},
			{"day":5,"start":0,"end":24,"type":"sleep"},
			{"day":6,"start":0,"end":24,"type":"sleep"},*/
	 {"day":0 ,"name": "sleep","start":10,"end":18},//
	 
	 {"day":1 ,"name": "sleep","start":14,"end":22},
	 

	 {"day":2 ,"name": "sleep","start":18,"end":24},
	 
	 {"day":3 ,"name": "sleep","start":0,"end":2},
	 {"day":3 ,"name": "sleep","start":2,"end":24},
	 
	 {"day":4 ,"name": "sleep","start":0,"end":6},
	 
	 {"day":5 ,"name": "sleep","start":2,"end":10},
	
	 {"day":6 ,"name": "sleep","start":6,"end":14},
	
		]
		g = svg.append("g")
			.attr("transform", "translate(" + width / 2 + "," + height / 2 + ")");
		
		
		g.append("g")
			.attr("class", "tracks")
			.selectAll("circle")
			.data(fields)
			.enter().append("circle")
			.attr("r", function(d) { return d.radius; });
		
		g.append("g")
			.attr("class", "week")
			.selectAll("g")
			.data(week_schedule)
			.enter().append("g")
			.append("path")
			.attr("d", function(d){
				return week_arc(d);
			}).attr("fill", function(d) { 
				if(d.name=="sleep") return "#000";
				if(d.name=="wake") return "#fff";
				return "#fda"; 
			})
		

		body = g.append("g")
			.attr("class", "bodies")
			.selectAll("g")
			.data(fields)
			.enter().append("g");


		
		body.append("path")
			.attr("d", function(d) {
					return arcBody(d);});

			
		
		start_clock();
	}
	
	function tick() {
		var now = Date.now()-time_zone_offset*60*1000;
	
		fields.forEach(function(d,i) {
			var start = dial.start(now,d.index),
			end = dial.offset(start,d.index);
			d.angle = Math.round((now - start) / (end - start) * 360 * 100) / 100;
		});
	
		body
		.style("fill", function(d) { return color(d.angle); })
		.attr("transform", function(d) { offset = 0; if(d.index==4) offset = 0; return "rotate(" + d.angle+offset + ")"; });
	
		bodyText
		.attr("startOffset", function(d, i) { return d.angle <= 90 || d.angle > 270 ? "100%" : "0%"; })
		.attr("text-anchor", function(d, i) { return d.angle <= 90 || d.angle > 270 ? "end" : "start"; })
		.text(function(d,i) { return dial.format(now,i); });
	}
	
	var start_clock=function(){
		body.append("path")
		.attr("class", "text-path")
		.attr("id", function(d, i) { return "body-text-path-" + i; })
		.attr("d", arcTextPath);
		
		bodyText = body.append("text")
		.attr("dy", ".35em")
		.append("textPath")
		.style("font-size",0.05*radius)
		.attr("xlink:href", function(d, i) { return "#body-text-path-" + i; });
		
		tick();
		
		d3.timer(tick);
	}
	return {
		init:init,
	}
})();
