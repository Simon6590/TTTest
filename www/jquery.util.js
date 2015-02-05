(function($){
$.util = function(){}
var u=$.util;
/**
*用法
* $.u.pie.Constructor(data,{option})
*/
u.reDraw=function(canvasType,data){
switch (canvasType){
	case 'pie':
	data = (function (){
	var data = [],
			series = Math.floor(Math.random() * 6) + 3;
		for (var i = 0; i < series; i++) {
			data[i] = {
				label: "Series" + (i + 1),
				data: Math.floor(Math.random() * 100) + 1
			}
		}
		return data;
	})();
	break;
	case 'line':
	data =(function (){
		var sin = [],
		cos = [];
		for (var i = 0; i < 14; i += 0.5) {
			sin.push([i, Math.sin(i)*Math.random()]);
			cos.push([i, Math.cos(i)*Math.random()]);
		}
			return [{ data: sin, label: "sin(x)"},{ data: cos, label: "cos(x)"}];
		})();
		break;
	case 'pillar':
		data = [[ ["January", Math.random()*4],["April",  Math.random()*13], ["May",  Math.random()*89],["June",  Math.random()*9] ] ];
}
this[canvasType].reDraw(data);
}
u["pie"] ={//饼图
	"self":{},
	text:'<div class="demo-container"><input type="button" value="异步取数据" onclick=$$.util.reDraw("pie","data") />'+
	'<div id="placeholder" class="demo-placeholder"></div></div>',
	id:'placeholder',
	html:function(){
			u.display(this.text);
			return this;
			},
	Constructor:function(type){
		$("#"+type).html("");
		$("#"+type).html(this.text);
			var placeholder =$('#'+this.id),data=[];
			alert(placeholder.width());
			placeholder.unbind();
			var series = Math.floor(Math.random() * 6) + 3;
					for (var i = 0; i < series; i++) {
						data[i] = {
							label: "Series" + (i + 1),
							data: Math.floor(Math.random() * 100) + 1
							}
						}
		this.self = $.plot(placeholder, data, {
						series: {//数据是一个数列数组
							pie: {//饼状图
								show: true
							}
						},
						legend: {
							show: false
						},
						grid: {
							show:true,
							//markings:[{xaxis:{from:0, to:2}, yaxis: {from:10,to: 0},color:"#bb0340"}]
							hoverable: true,//允许监听鼠标悬停事件
							clickable: true//允许监听鼠标点击事件
						}
					});
		placeholder.bind("plothover", function(event, pos, obj) {
				if (!obj) {
					return;
				}
				var percent = parseFloat(obj.series.percent).toFixed(2);
				$("#hover").html("<span style='font-weight:bold; color:" + obj.series.color + "'>" + obj.series.label + " (" + percent + "%)</span>");
			});
			placeholder.bind("plotclick", function(event, pos, obj) {
				if (!obj) {
					return;
				}
				percent = parseFloat(obj.series.percent).toFixed(0);
				alert(""  + obj.series.label + ": " + percent + "%");
			});
			},
			reDraw:function(data){
			 if($.isArray(data)){
				this.self.setData(data);
				this.self.draw();
				}
				else
				 throw new Error('the parameter is a Array' );
			}
};
u["line"]={//线图
	"self":{},
	text:'<div class="demo-container"><input type="button" value="异步取数据" onclick=$$.util.reDraw("line","data") /><div id="placeholder" class="demo-placeholder"></div></div>',
	id:'placeholder',
	html:function(){
			u.display(this.text);
			return this;
			},
	Constructor:function(type){
	$("#"+type).html("");
	$("#"+type).html(this.text);
	var placeholder =$('#'+this.id);
			placeholder.unbind();
		var sin = [],
			cos = [];
			for (var i = 0; i < 14; i += 0.5) {
			sin.push([i, Math.sin(i)]);
			cos.push([i, Math.cos(i)]);
		}
			this.self = $.plot(placeholder, [
			{ data: sin, label: "sin(x)"},
			{ data: cos, label: "cos(x)"}
		], {
			series: {
				lines: {//线图
					show: true//是否显示连线
				},
				points: {
					show: true//显示点
				}
			},
			crosshair: {mode: "xy"},//插件显示,鼠标移动显示xy坐标
			grid: {
				hoverable: true,
				clickable: true
			},//数轴定制
			yaxis: {//mode: null or "time"  //数轴是否为时间模式min: null or number  //数轴最小值 max: null or number  //数轴最大值
				min: -1.2,
				max: 1.2
			},
			 legend:{
			 labelFormatter: function(label, series) {
    				// series is the series object for the label  //series是名称为label的曲线的数据对象
   				 return '<a href="javascript:void(0);">' + label + '</a>';
  					}
  				}
		});
		function showTooltip(x, y, contents) {
			$("<div id='tooltip'>" + contents + "</div>").css({
				position: "absolute",
				display: "none",
				top: y + 5,
				left: x + 5,
				border: "1px solid #fdd",
				padding: "2px",
				"background-color": "#fee",
				"z-index":200,
				opacity: 0.80
			}).appendTo("body").fadeIn(200);
		}

		var previousPoint = null;
		$("#placeholder").bind("plothover", function (event, pos, item) {
				if (item) {
					if (previousPoint != item.dataIndex) {

						previousPoint = item.dataIndex;

						$("#tooltip").remove();
						var x = item.datapoint[0].toFixed(2),
						y = item.datapoint[1].toFixed(2);

						showTooltip(item.pageX, item.pageY,
						    item.series.label + " of " + x + " = " + y);
					}
				} else {
					$("#tooltip").remove();
					previousPoint = null;            
				}
		});

		$("#placeholder").bind("plotclick", function (event, pos, item) {
			if (item) {
				$("#clickdata").text(" - click point " + item.dataIndex + " in " + item.series.label);
				plot.highlight(item.series, item.datapoint);
			}
		});
			},
			reDraw:function(data){//重绘实现动态请求数据
			if($.isArray(data)){
				this.self.setData(data);
				this.self.draw();
				}
				else
				 throw new Error('the parameter is a Array' );
			}
};
u["pillar"]={//柱图
"self":{},
	text:'<div class="demo-container"><input type="button" value="异步取数据" onclick=$$.util.reDraw("pillar","data") /><div id="placeholder" class="demo-placeholder"></div></div>',
	id:'placeholder',
	html:function(){
			u.display(this.text);
			return this;
			},
	Constructor:function(type){
	$("#"+type).html("");
		$("#"+type).html(this.text);
		var data = [["January", 4], ["April", 13], ["May", 89], ["June", 9] ];
		this.self = $.plot("#placeholder", [ data ], {
			series: {
				bars: {
					show: true,
					barWidth: 0.6,
					align: "center"
				}
			},
			xaxis: {
				mode: "categories",
				tickLength: 0
			}
		});
			},
			reDraw:function(data){
				if($.isArray(data)){
				this.self.setData(data);
				this.self.draw();
				}
				else
				 throw new Error('the parameter is a Array' );
			}
}
u.showCanvas = function(canvasType ,data,targetDiv){
	this[canvasType].Constructor(targetDiv);
	}
	})(jQuery);