<!DOCTYPE html>
<!--[if IE 7]>
<html class="ie ie7" lang="en-US" prefix="og: http://ogp.me/ns#">
<![endif]-->
<!--[if IE 8]>
<html class="ie ie8" lang="en-US" prefix="og: http://ogp.me/ns#">
<![endif]-->
<!--[if !(IE 7) | !(IE 8)  ]><!-->
<html lang="en-US" prefix="og: http://ogp.me/ns#">
<!--<![endif]-->
<head>
<meta charset="UTF-8" />
<meta name="viewport" content="width=device-width" />
<meta name="description" content="A Computer Science portal for geeks. It contains well written, well thought and well explained computer science and programming articles, quizzes and practice/competitive programming/company interview Questions.">
<link rel="shortcut icon" href="/gfg.png" type="image/x-icon" />

<meta property="og:image" content="http://www.geeksforgeeks.org/wp-content/uploads/gfg_200X200.png">
<meta property="og:image:type" content="image/png">
<meta property="og:image:width" content="200">
<meta property="og:image:height" content="200">

<title>C Programming Language - GeeksforGeeks</title>
<link rel="profile" href="http://gmpg.org/xfn/11" />
<link rel="pingback" href="" />
<!--[if lt IE 9]>
<script src="http://www.geeksforgeeks.org/wp-content/themes/iconic-one/js/html5.js" type="text/javascript"></script>
<![endif]-->
<script>
    var domain = 1;
    var arrPost = new Array();
    var post_id = "24966";
    var post_type = "page";
    var post_slug = window.location.href;
    var ip = "52.56.127.14";
    var post_title = "C Programming Language";
    var post_status = "publish";
                            var isAdminLoggedIn = 0;
        </script>

<!-- This site is optimized with the Yoast SEO plugin v3.7.1 - https://yoast.com/wordpress/plugins/seo/ -->
<link rel="canonical" href="http://www.geeksforgeeks.org/c/" />
<meta property="og:locale" content="en_US" />
<meta property="og:type" content="article" />
<meta property="og:title" content="C Programming Language - GeeksforGeeks" />
<meta property="og:description" content="Recent Articles on C ! Basics,   Variable Declaration, Definition and Scope,   Data Types,   Storage Classes,   Input/Output,   Operators,   Preprocessor,  … Read More &raquo;" />
<meta property="og:url" content="http://www.geeksforgeeks.org/c/" />
<meta property="og:site_name" content="GeeksforGeeks" />
<!-- / Yoast SEO plugin. -->

<link rel='dns-prefetch' href='//www.geeksforgeeks.org' />
<link rel='dns-prefetch' href='//fonts.googleapis.com' />
<link rel='dns-prefetch' href='//s.w.org' />
<link rel="alternate" type="application/rss+xml" title="GeeksforGeeks &raquo; Feed" href="http://www.geeksforgeeks.org/feed/" />
<link rel="alternate" type="application/rss+xml" title="GeeksforGeeks &raquo; Comments Feed" href="http://www.geeksforgeeks.org/comments/feed/" />
<link rel="alternate" type="application/rss+xml" title="GeeksforGeeks &raquo; C Programming Language Comments Feed" href="http://www.geeksforgeeks.org/c/feed/" />
		<script type="text/javascript">
			window._wpemojiSettings = {"baseUrl":"https:\/\/s.w.org\/images\/core\/emoji\/2\/72x72\/","ext":".png","svgUrl":"https:\/\/s.w.org\/images\/core\/emoji\/2\/svg\/","svgExt":".svg","source":{"concatemoji":"http:\/\/www.geeksforgeeks.org\/wp-includes\/js\/wp-emoji-release.min.js"}};
			!function(a,b,c){function d(a){var c,d,e,f,g,h=b.createElement("canvas"),i=h.getContext&&h.getContext("2d"),j=String.fromCharCode;if(!i||!i.fillText)return!1;switch(i.textBaseline="top",i.font="600 32px Arial",a){case"flag":return i.fillText(j(55356,56806,55356,56826),0,0),!(h.toDataURL().length<3e3)&&(i.clearRect(0,0,h.width,h.height),i.fillText(j(55356,57331,65039,8205,55356,57096),0,0),c=h.toDataURL(),i.clearRect(0,0,h.width,h.height),i.fillText(j(55356,57331,55356,57096),0,0),d=h.toDataURL(),c!==d);case"diversity":return i.fillText(j(55356,57221),0,0),e=i.getImageData(16,16,1,1).data,f=e[0]+","+e[1]+","+e[2]+","+e[3],i.fillText(j(55356,57221,55356,57343),0,0),e=i.getImageData(16,16,1,1).data,g=e[0]+","+e[1]+","+e[2]+","+e[3],f!==g;case"simple":return i.fillText(j(55357,56835),0,0),0!==i.getImageData(16,16,1,1).data[0];case"unicode8":return i.fillText(j(55356,57135),0,0),0!==i.getImageData(16,16,1,1).data[0];case"unicode9":return i.fillText(j(55358,56631),0,0),0!==i.getImageData(16,16,1,1).data[0]}return!1}function e(a){var c=b.createElement("script");c.src=a,c.type="text/javascript",b.getElementsByTagName("head")[0].appendChild(c)}var f,g,h,i;for(i=Array("simple","flag","unicode8","diversity","unicode9"),c.supports={everything:!0,everythingExceptFlag:!0},h=0;h<i.length;h++)c.supports[i[h]]=d(i[h]),c.supports.everything=c.supports.everything&&c.supports[i[h]],"flag"!==i[h]&&(c.supports.everythingExceptFlag=c.supports.everythingExceptFlag&&c.supports[i[h]]);c.supports.everythingExceptFlag=c.supports.everythingExceptFlag&&!c.supports.flag,c.DOMReady=!1,c.readyCallback=function(){c.DOMReady=!0},c.supports.everything||(g=function(){c.readyCallback()},b.addEventListener?(b.addEventListener("DOMContentLoaded",g,!1),a.addEventListener("load",g,!1)):(a.attachEvent("onload",g),b.attachEvent("onreadystatechange",function(){"complete"===b.readyState&&c.readyCallback()})),f=c.source||{},f.concatemoji?e(f.concatemoji):f.wpemoji&&f.twemoji&&(e(f.twemoji),e(f.wpemoji)))}(window,document,window._wpemojiSettings);
		</script>
		<style type="text/css">
img.wp-smiley,
img.emoji {
	display: inline !important;
	border: none !important;
	box-shadow: none !important;
	height: 1em !important;
	width: 1em !important;
	margin: 0 .07em !important;
	vertical-align: -0.1em !important;
	background: none !important;
	padding: 0 !important;
}
</style>
<link rel='stylesheet' id='mtq_CoreStyleSheets-css'  href='http://www.geeksforgeeks.org/wp-content/plugins/mtouch-quiz/mtq_core_style.min.css' type='text/css' media='all' />
<link rel='stylesheet' id='mtq_ThemeStyleSheets-css'  href='http://www.geeksforgeeks.org/wp-content/plugins/mtouch-quiz/mtq_theme_style.min.css' type='text/css' media='all' />
<link rel='stylesheet' id='wp-quicklatex-format-css'  href='http://www.geeksforgeeks.org/wp-content/plugins/wp-quicklatex/css/quicklatex-format.css' type='text/css' media='all' />
<link rel='stylesheet' id='themonic-fonts-css'  href='http://fonts.googleapis.com/css?family=Ubuntu:400,700&#038;subset=latin,latin-ext' type='text/css' media='all' />
<link rel='stylesheet' id='custom-style-css'  href='http://www.geeksforgeeks.org/wp-content/themes/iconic-one/css/gfg-1.2.css' type='text/css' media='all' />
<script type='text/javascript' src='http://www.geeksforgeeks.org/wp-includes/js/jquery/jquery.js'></script>
<script type='text/javascript' src='http://www.geeksforgeeks.org/wp-includes/js/jquery/jquery-migrate.min.js'></script>
<script type='text/javascript' src='http://www.geeksforgeeks.org/wp-content/themes/iconic-one/js/gfg-5.0.js'></script>
<link rel='https://api.w.org/' href='http://www.geeksforgeeks.org/wp-json/' />
<link rel="EditURI" type="application/rsd+xml" title="RSD" href="http://www.cdn.geeksforgeeks.org/xmlrpc.php?rsd" />
<link rel="wlwmanifest" type="application/wlwmanifest+xml" href="http://www.geeksforgeeks.org/wp-includes/wlwmanifest.xml" /> 
<meta name="generator" content="WordPress 4.6.5" />
<link rel='shortlink' href='http://www.geeksforgeeks.org/?p=24966' />
<link rel="alternate" type="application/json+oembed" href="http://www.geeksforgeeks.org/wp-json/oembed/1.0/embed?url=http%3A%2F%2Fwww.geeksforgeeks.org%2Fc%2F" />
<link rel="alternate" type="text/xml+oembed" href="http://www.geeksforgeeks.org/wp-json/oembed/1.0/embed?url=http%3A%2F%2Fwww.geeksforgeeks.org%2Fc%2F&#038;format=xml" />
<style>
#wpadminbar{
background: #ff0000 !important;
}
</style>
<style type="text/css" id="custom-background-css">
body.custom-background { background-color: #ffffff; }
</style>
<style type="text/css" id="syntaxhighlighteranchor"></style>

<script type='text/javascript'>
  var googletag = googletag || {};
  googletag.cmd = googletag.cmd || [];
  (function() {
    var gads = document.createElement('script');
    gads.async = true;
    gads.type = 'text/javascript';
    var useSSL = 'https:' == document.location.protocol;
    gads.src = (useSSL ? 'https:' : 'http:') +
      '//www.googletagservices.com/tag/js/gpt.js';
    var node = document.getElementsByTagName('script')[0];
    node.parentNode.insertBefore(gads, node);
  })();
</script>

<script type='text/javascript'>
  googletag.cmd.push(function() {
    googletag.defineSlot('/27823234/SP', [300, 250], 'div-gpt-ad-1458112424022-0').addService(googletag.pubads());
    googletag.pubads().enableSingleRequest();
    googletag.enableServices();
  });
</script>
</head>

<body class="page page-id-24966 page-template-default custom-background custom-background-white custom-font-enabled">

<!-- BuySellAds Ad Code -->
<script type="text/javascript">
(function(){
  var bsa = document.createElement('script');
     bsa.type = 'text/javascript';
     bsa.async = true;
     bsa.src = '//s3.buysellads.com/ac/bsa.js';
  (document.getElementsByTagName('head')[0]||document.getElementsByTagName('body')[0]).appendChild(bsa);
})();
</script>
<!-- End BuySellAds Ad Code -->

<div id="page" style="position:relative;" class="hfeed site">
	<header id="masthead" class="site-header" role="banner">
		<div style="margin-bottom: 5px;">	
				<hgroup class="main_gfg_title">
			<a href="http://www.geeksforgeeks.org/" title="GeeksforGeeks" rel="home">GeeksforGeeks</a>
				<br .../> <a class="site-description">A computer science portal for geeks</a>
		</hgroup>
		<span class="responsive-custom-search">
<script>
  (function() {
    var cx = '009682134359037907028:tj6eafkv_be';
    var gcse = document.createElement('script');
    gcse.type = 'text/javascript';
    gcse.async = true;
    gcse.src = (document.location.protocol == 'https:' ? 'https:' : 'http:') +
        '//cse.google.com/cse.js?cx=' + cx;
    var s = document.getElementsByTagName('script')[0];
    s.parentNode.insertBefore(gcse, s);
  })();
</script>
		
		<gcse:search></gcse:search>  
		</span>

<div class="top-button-div">
<hgroup style="float:right;display:inline-block;margin-top:5px;">   


<a class="products" href="http://practice.geeksforgeeks.org/">Practice</a>

<a class="products" href="http://quiz.geeksforgeeks.org/gate-corner-2/">GATE CS</a>

<a class="products" href="http://quiz.geeksforgeeks.org/placements/">Placements</a>

<a class="products" href="https://www.youtube.com/geeksforgeeksvideos/">Videos</a>

<a class="products" href="http://www.geeksforgeeks.org/contribute/">Contribute</a>
</hgroup><br></br>


<div id="profile" style="float: right; margin-top: -1%;margin-right:1%;"></div>
</div>
</div>

		
		
		<nav id="site-navigation" class="themonic-nav" role="navigation">
			<a class="assistive-text" href="#content" title="Skip to content">Skip to content</a>
			<div class="menu-iconic-container"><ul id="menu-top" class="nav-menu"><li id="menu-item-147519" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147519"><a href="/"><img style="width: 30px;vertical-align: middle;" src="http://www.geeksforgeeks.org/wp-content/uploads/gfg_transparent_white_small.png"></a></li>
<li id="menu-item-141975" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-141975"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/">Algo ▼</a>
<ul class="sub-menu">
	<li id="menu-item-135030" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135030"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#AnalysisofAlgorithms">Analysis of Algorithms</a></li>
	<li id="menu-item-146823" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146823"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/">Topicwise ►</a>
	<ul class="sub-menu">
		<li id="menu-item-147774" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147774"><a href="http://www.geeksforgeeks.org/searching-algorithms/">Searching Algorithms</a></li>
		<li id="menu-item-147773" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147773"><a href="http://www.cdn.geeksforgeeks.org/sorting-algorithms/">Sorting Algorithms</a></li>
		<li id="menu-item-135041" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135041"><a href="http://www.geeksforgeeks.org/graph-data-structure-and-algorithms/">Graph Algorithms</a></li>
		<li id="menu-item-135040" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135040"><a href="http://www.geeksforgeeks.org/bitwise-algorithms/">Bit Algorithms</a></li>
		<li id="menu-item-135034" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135034"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#PatternSearching">Pattern Searching</a></li>
		<li id="menu-item-135038" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135038"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#GeometricAlgorithms">Geometric Algorithms</a></li>
		<li id="menu-item-135039" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135039"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#MathematicalAlgorithms">Mathematical Algorithms</a></li>
		<li id="menu-item-135042" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135042"><a href="http://www.geeksforgeeks.org/randomized-algorithms/">Randomized Algorithms</a></li>
	</ul>
</li>
	<li id="menu-item-146824" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146824"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/">Algorithm Paradigms ►</a>
	<ul class="sub-menu">
		<li id="menu-item-135032" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135032"><a href="http://www.geeksforgeeks.org/greedy-algorithms/">Greedy Algorithms</a></li>
		<li id="menu-item-135033" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135033"><a href="http://www.geeksforgeeks.org/dynamic-programming/">Dynamic Programming</a></li>
		<li id="menu-item-135037" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135037"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#DivideandConquer">Divide and Conquer</a></li>
		<li id="menu-item-135036" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135036"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#Backtracking">Backtracking</a></li>
		<li id="menu-item-137933" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137933"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/#BranchandBound">Branch &#038; Bound</a></li>
	</ul>
</li>
	<li id="menu-item-146911" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146911"><a href="http://www.geeksforgeeks.org/fundamentals-of-algorithms/">All Algorithms</a></li>
</ul>
</li>
<li id="menu-item-142016" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-142016"><a href="http://www.geeksforgeeks.org/data-structures/">DS  ▼</a>
<ul class="sub-menu">
	<li id="menu-item-135054" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135054"><a href="http://www.geeksforgeeks.org/array-data-structure/">Array</a></li>
	<li id="menu-item-135045" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135045"><a href="http://www.geeksforgeeks.org/data-structures/linked-list/">LinkedList</a></li>
	<li id="menu-item-135046" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135046"><a href="http://www.geeksforgeeks.org/stack-data-structure/">Stack</a></li>
	<li id="menu-item-135047" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135047"><a href="http://www.geeksforgeeks.org/queue-data-structure/">Queue</a></li>
	<li id="menu-item-146827" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146827"><a href="http://www.geeksforgeeks.org/data-structures/">Tree based DS ►</a>
	<ul class="sub-menu">
		<li id="menu-item-135048" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135048"><a href="http://www.geeksforgeeks.org/binary-tree-data-structure/">Binary Tree</a></li>
		<li id="menu-item-135049" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135049"><a href="http://www.geeksforgeeks.org/binary-search-tree-data-structure/">Binary Search Tree</a></li>
		<li id="menu-item-135050" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135050"><a href="http://www.geeksforgeeks.org/heap-data-structure/">Heap</a></li>
	</ul>
</li>
	<li id="menu-item-135051" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135051"><a href="http://www.geeksforgeeks.org/hashing-data-structure/">Hashing</a></li>
	<li id="menu-item-135052" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135052"><a href="http://www.geeksforgeeks.org/graph-data-structure-and-algorithms/">Graph</a></li>
	<li id="menu-item-135053" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135053"><a href="http://www.geeksforgeeks.org/advanced-data-structures/">Advanced Data Structure</a></li>
	<li id="menu-item-135055" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135055"><a href="http://www.geeksforgeeks.org/matrix/">Matrix</a></li>
	<li id="menu-item-147716" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147716"><a href="http://www.geeksforgeeks.org/category/data-structures/c-strings/">Strings</a></li>
	<li id="menu-item-135056" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135056"><a href="http://www.geeksforgeeks.org/data-structures/">All Data Structures</a></li>
</ul>
</li>
<li id="menu-item-147478" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-home current-menu-ancestor current-menu-parent menu-item-has-children menu-item-147478"><a href="http://www.geeksforgeeks.org/">Languages ▼</a>
<ul class="sub-menu">
	<li id="menu-item-135006" class="menu-item menu-item-type-post_type menu-item-object-page current-menu-item page_item page-item-24966 current_page_item menu-item-135006"><a href="http://www.geeksforgeeks.org/c/">C</a></li>
	<li id="menu-item-135007" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-135007"><a href="http://www.geeksforgeeks.org/c-plus-plus/">C++</a></li>
	<li id="menu-item-135012" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-135012"><a href="http://www.geeksforgeeks.org/java/">Java</a></li>
	<li id="menu-item-137004" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-137004"><a href="http://www.geeksforgeeks.org/python/">Python</a></li>
	<li id="menu-item-135016" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-135016"><a href="http://www.geeksforgeeks.org/sql-tutorial/">SQL</a></li>
	<li id="menu-item-140854" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-140854"><a href="http://www.geeksforgeeks.org/category/program-output/">Program Output</a></li>
</ul>
</li>
<li id="menu-item-142017" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-142017"><a href="http://www.geeksforgeeks.org/about/interview-corner/">Interview  ▼</a>
<ul class="sub-menu">
	<li id="menu-item-141326" class="menu-item menu-item-type-post_type menu-item-object-page menu-item-141326"><a href="http://www.geeksforgeeks.org/company-preparation/">Company Prep</a></li>
	<li id="menu-item-137171" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137171"><a href="http://www.geeksforgeeks.org/interview-preparation-for-software-developer/">Top Topics</a></li>
	<li id="menu-item-137172" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137172"><a href="http://www.practice.geeksforgeeks.org/tags.php?">Practice Company Questions</a></li>
	<li id="menu-item-137173" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137173"><a href="http://www.geeksforgeeks.org/about/interview-corner/">Interview Experiences</a></li>
	<li id="menu-item-137174" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137174"><a href="http://www.geeksforgeeks.org/category/interview-experiences/experienced-interview-experiences/">Experienced Interviews</a></li>
	<li id="menu-item-137175" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137175"><a href="http://www.geeksforgeeks.org/category/interview-experiences/internship-interview-experiences/">Internship Interviews</a></li>
	<li id="menu-item-137176" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137176"><a href="http://www.geeksforgeeks.org/category/competitive-programming/">Competitive Programming</a></li>
	<li id="menu-item-147581" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147581"><a href="http://www.geeksforgeeks.org/software-design-patterns/">Design Patterns</a></li>
	<li id="menu-item-137186" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137186"><a href="http://geeksquiz.com/quiz-corner/">Multiple Choice Quizzes</a></li>
</ul>
</li>
<li id="menu-item-137178" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-137178"><a href="http://www.geeksforgeeks.org/student-corner/">Students  ▼</a>
<ul class="sub-menu">
	<li id="menu-item-137183" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137183"><a href="http://www.geeksforgeeks.org/campus-ambassador-program-by-geeksforgeeks/">Campus Ambassador Program</a></li>
	<li id="menu-item-137179" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137179"><a href="http://www.geeksforgeeks.org/geek-of-the-month/">Geek of the Month</a></li>
	<li id="menu-item-137570" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137570"><a href="http://geeksquiz.com/placements/">Placement Course</a></li>
	<li id="menu-item-136004" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-136004"><a href="http://www.geeksforgeeks.org/category/project/">Project</a></li>
	<li id="menu-item-137180" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137180"><a href="http://www.geeksforgeeks.org/category/competitive-programming/">Competitive Programming</a></li>
	<li id="menu-item-137181" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137181"><a href="http://www.geeksforgeeks.org/testimonials/">Testimonials</a></li>
	<li id="menu-item-138863" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-138863"><a href="http://www.geeksforgeeks.org/category/geek-on-the-top/">Geek on the Top</a></li>
	<li id="menu-item-141974" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-141974"><a href="http://www.geeksforgeeks.org/jobs/">Jobs</a></li>
	<li id="menu-item-137378" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-137378"><a href="http://www.geeksforgeeks.org/internship/">Internship</a></li>
	<li id="menu-item-147457" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147457"><a href="http://www.geeksforgeeks.org/school-programming/">School Programming</a></li>
</ul>
</li>
<li id="menu-item-146712" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146712"><a href="http://www.geeksforgeeks.org/gate-corner-2-gq/">GATE ▼</a>
<ul class="sub-menu">
	<li id="menu-item-146713" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146713"><a href="http://www.geeksforgeeks.org/gate-corner-2-gq/">GATE CS Corner</a></li>
	<li id="menu-item-146714" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146714"><a href="http://www.geeksforgeeks.org/gate-cs-notes-gq/">GATE Notes</a></li>
	<li id="menu-item-146715" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146715"><a href="http://www.geeksforgeeks.org/lmns-gq/">Last Minute Notes</a></li>
	<li id="menu-item-146716" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146716"><a href="http://www.geeksforgeeks.org/original-gate-previous-year-question-papers-cse-and-it-gq/">Official Papers</a></li>
	<li id="menu-item-146717" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146717"><a href="http://www.geeksforgeeks.org/gate-2017-important-dates-and-links/">Gate 2017 Important Dates and Links</a></li>
</ul>
</li>
<li id="menu-item-146718" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146718"><a href="http://www.geeksforgeeks.org/articles-on-computer-science-subjects-gq/">CS Subjects ▼</a>
<ul class="sub-menu">
	<li id="menu-item-146729" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146729"><a href="http://www.geeksforgeeks.org/operating-systems/">Operating Systems</a></li>
	<li id="menu-item-146724" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146724"><a href="http://www.geeksforgeeks.org/dbms/">DBMS</a></li>
	<li id="menu-item-146721" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146721"><a href="http://www.geeksforgeeks.org/computer-network-tutorials/">Computer Networks</a></li>
	<li id="menu-item-146720" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146720"><a href="http://www.geeksforgeeks.org/compiler-design-tutorials/">Compiler Design</a></li>
	<li id="menu-item-147831" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147831"><a href="http://www.geeksforgeeks.org/web-technology/">Web Technology</a></li>
	<li id="menu-item-146722" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146722"><a href="http://www.geeksforgeeks.org/computer-organization-and-architecture-tutorials/">Computer Organization &#038; Architecture</a></li>
	<li id="menu-item-146726" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146726"><a href="http://www.geeksforgeeks.org/digital-electronics-logic-design-tutorials/">Digital Electronics</a></li>
	<li id="menu-item-146727" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146727"><a href="http://www.geeksforgeeks.org/engineering-mathematics-tutorials/">Engg. Mathematics</a></li>
	<li id="menu-item-146730" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146730"><a href="http://www.geeksforgeeks.org/theory-of-computation-automata-tutorials/">Theory of Computation</a></li>
	<li id="menu-item-147512" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-147512"><a href="http://www.geeksforgeeks.org/advanced-computer-subjects-tutorials/">Advanced Topics</a></li>
	<li id="menu-item-146725" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146725"><a href="http://www.geeksforgeeks.org/category/geeksquiz/articles-gq/difference-gq/">What&#8217;s Difference?</a></li>
</ul>
</li>
<li id="menu-item-140855" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-140855"><a href="http://quiz.geeksforgeeks.org/quiz-corner/">Quizzes ▼</a>
<ul class="sub-menu">
	<li id="menu-item-146748" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146748"><a href="http://www.geeksforgeeks.org/quizzes-on-programming-languages-gq/">Languages ►</a>
	<ul class="sub-menu">
		<li id="menu-item-146743" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146743"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#C%20Programming%20Mock%20Tests">C</a></li>
		<li id="menu-item-146745" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146745"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#C++%20Programming%20Mock%20Tests">C++</a></li>
		<li id="menu-item-146746" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146746"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Java%20Programming%20Mock%20Tests">Java</a></li>
		<li id="menu-item-146747" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146747"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Python%20Programming%20Mock%20Tests">Python</a></li>
	</ul>
</li>
	<li id="menu-item-146825" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-has-children menu-item-146825"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Data%20Structures%20Mock%20Tests">CS Subjectwise ►</a>
	<ul class="sub-menu">
		<li id="menu-item-146731" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146731"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Data%20Structures%20Mock%20Tests">Data Structures</a></li>
		<li id="menu-item-146732" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146732"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Algorithms%20Mock%20Tests">Algorithms</a></li>
		<li id="menu-item-146733" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146733"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Operating%20Systems%20Mock%20Tests">Operating Systems</a></li>
		<li id="menu-item-146734" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146734"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#DBMS%20Mock%20Tests">DBMS</a></li>
		<li id="menu-item-146735" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146735"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Compiler%20Design%20Mock%20Tests">Compiler Design</a></li>
		<li id="menu-item-146736" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146736"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Computer%20Networks%20Mock%20Tests">Computer Networks</a></li>
		<li id="menu-item-146737" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146737"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Theory%20of%20Computation%20Mock%20Tests">Theory of Computation</a></li>
		<li id="menu-item-146738" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146738"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Computer%20Organization%20and%20Architecture">Computer Organization</a></li>
		<li id="menu-item-146739" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146739"><a href="http://www.geeksforgeeks.org/software-engineering-gq/">Software Engineering</a></li>
	</ul>
</li>
	<li id="menu-item-146740" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146740"><a href="http://www.geeksforgeeks.org/html-and-xml-gq/">HTML &#038; XML</a></li>
	<li id="menu-item-146741" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146741"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Engineering%20Mathematics">Engg. Mathematics</a></li>
	<li id="menu-item-146742" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-146742"><a href="http://www.geeksforgeeks.org/quiz-corner-gq/#Aptitude%20Mock%20Tests">Aptitude</a></li>
</ul>
</li>
<li id="menu-item-135367" class="menu-item menu-item-type-taxonomy menu-item-object-category menu-item-135367"><a href="http://www.geeksforgeeks.org/category/guestblogs/">GBlog</a></li>
<li id="menu-item-141885" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-141885"><a href="http://www.geeksforgeeks.org/puzzles/">Puzzles</a></li>
<li id="menu-item-141816" class="menu-item menu-item-type-custom menu-item-object-custom menu-item-141816"><a href="http://www.geeksforgeeks.org/progeek-cup-1-0-project-competition-geeksforgeeks/">What&#8217;s New?</a></li>
</ul></div>		</nav><!-- #site-navigation -->
		<div class="clear"></div>
	</header><!-- #masthead -->
<button id="scrollTopBtn" title="Scroll to Top" type="button" class="btn btn-success">&#x25B2;</button>
	<div id="main" class="wrapper">
<div class="leftSideBarParent">
    <div class="leftSideBar">
        <div class="menuDivForLeftbar"><div class="bar1"></div><div class="bar2"></div><div class="bar3"></div></div><span class="leftbarDataSpan" data-pid="24966" data-lid="1" data-type="page" data-termid="0"></span><div class="quickLink_S">
<table>
<tbody>

<tr>
<td class="quickLink-header_S"><b>Interview Preparation</td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/company-preparation/">Company Preparation</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/interview-preparation-for-software-developer/">Top Topics</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/placements-gq/">Placements</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/company-interview-corner/">Interview Corner</a></td>
</tr>


<tr>
<td><a href="http://www.geeksforgeeks.org/category/interview-experiences/">Recent Interview Experiences</a></td>
</tr>


<tr>
<td><a href="http://www.geeksforgeeks.org/geeksquiz-home/">GQ Home Page</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/quiz-corner-gq/">Quiz Corner</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/lmns-gq/">LMNs</a></td>
</tr>

<tr>
<td class="quickLink-header_S"><b>Practice Platform</b></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/recent.php?ref=home">What's New ?</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/ranking.php?ref=home">Leaderboard !!</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/company-tags/?ref=home">Company-wise Problems</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/topic-tags/?ref=home">Topic-wise Problems</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/subjective-page.php?ref=home">Subjective Problems</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/School/0/0/?ref=home">Difficulty Level - School</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/Basic/0/0/?ref=home">Difficulty Level - Basic</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/Easy/0/0/?ref=home">Difficulty Level - Easy</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/Medium/0/0/?ref=home">Difficulty Level - Medium</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/Hard/0/0/?ref=home">Difficulty Level - Hard</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/pickACategory.php?ref=home">How to pick a difficulty level?</a></td>
</tr>

<tr>
<td><a href="http://practice.geeksforgeeks.org/?ref=home">Explore More...</a></td>
</tr>


<tr>
<td class="quickLink-header_S"><b>Programming Languages</b></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/c/">C</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/c-plus-plus/">C++</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/java/">Java</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/python/">Python</a></td>
</tr>


<tr>
<td><a href="http://www.geeksforgeeks.org/sql-tutorial/">SQL</a></td>
</tr>


<tr>
<td class="quickLink-header_S"><b>Important Quick Links</b></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/school-programming/">School Programming</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/operating-systems/">Operating Systems</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/dbms/">DBMS</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/computer-network-tutorials/">Computer Networks</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/engineering-mathematics-tutorials/">Engineering Mathematics</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/category/design-pattern/">Design Patterns</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/category/puzzles/">Common Interview Puzzles</a></td>
</tr>


<tr>
<td><a href="http://www.geeksforgeeks.org/web-technology/">Web Technology</a></td>

<tr>
<td><a href="http://www.geeksforgeeks.org/category/gfact/">G-Facts</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/tag/computer-graphics/">Computer Graphics</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/tag/image-processing/">Image Processing</a></td>
</tr>

<tr>
<td><a href="http://www.geeksforgeeks.org/category/project/">Project Ideas</a></td>
</tr>

</tbody>
</table>
</div>    </div>
</div>

	<div id="primary" class="site-content">
		<div id="content" role="main">

							
	<article id="post-24966" class="post-24966 page type-page status-publish hentry">
		<div class="entry-content">
			<p><a href="http://www.geeksforgeeks.org/category/c/" style="padding: 5px;background-color: #4CB96B;color: #fff;"><strong>Recent Articles on C !</strong></a></p>
<p><a href="#Basics">Basics</a>,   <a href="#VariableDeclarationDefinitionandScope">Variable Declaration, Definition and Scope</a>,   <a href="#DataTypes">Data Types</a>,   <a href="#StorageClasses">Storage Classes</a>,   <a href="#InputOutput">Input/Output</a>,   <a href="#Operators">Operators</a>,   <a href="#Preprocessor">Preprocessor</a>,   <a href="#Array&amp;Strings">Array &amp; Strings</a>,   <a href="#ControlStatements">Control Statements</a>,   <a href="#Functions">Functions</a>,   <a href="#Pointers">Pointers</a>,   <a href="#EnumStructandUnion">Enum, Struct and Union</a>,   <a href="#MemoryManagement">Memory Management</a>,   <a href="#FileHandling">File Handling</a>,   <a href="#Puzzles">Puzzles</a>,   <a href="#Misc">Misc</a>,   <a href="#CLanguageInterviewQuestions">C Language Interview Questions</a>, <a href="http://www.geeksforgeeks.org/c-multiple-choice-questions/">Multiple Choice Questions</a></p>
<div style="width: 50%; float: left;">
<p style="text-align: center;"><strong><a name="Basics"></a>Basics: </strong></p>
<ol>
<li><a href="http://geeksquiz.com/c-language-set-1-introduction/" target="_blank">C Language Introduction</a></li>
<li><a href="http://www.geeksforgeeks.org/c-programming-language-standard/">C Programming Language Standard</a></li>
<li><a href="http://www.geeksforgeeks.org/fine-write-void-main-cc/">Is it fine to write “void main()” or “main()” in C/C++?</a></li>
<li><a href="http://www.geeksforgeeks.org/difference-int-main-int-mainvoid/">Difference between “int main()” and “int main(void)” in C/C++?</a></li>
<li><a href="http://www.geeksforgeeks.org/interesting-facts-preprocessors-c/" target="_blank">Macros and Preprocessors in C</a></li>
<li><a href="http://www.geeksforgeeks.org/compiling-a-c-program-behind-the-scenes/" target="_blank">Compiling a C program:- Behind the Scenes</a></li>
</ol>
<p style="text-align: center;"><strong><a name="VariableDeclarationDefinitionandScope"></a>Variable Declaration, Definition and Scope</strong>:</p>
<ol>
<li><a title="Permalink to Variables and Keywords in C" href="http://geeksquiz.com/variables-and-keywords-in-c/">Variables and Keywords in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-16/">How are variables scoped in C – Static or Dynamic?</a></li>
<li><a href="http://www.geeksforgeeks.org/scope-rules-in-c/">Scope rules in C</a></li>
<li><a href="http://www.geeksforgeeks.org/how-linkers-resolve-multiply-defined-global-symbols/">How Linkers Resolve Multiply Defined Global Symbols?</a></li>
<li><a href="http://geeksquiz.com/c-language-2/variable-declaration-and-scope/" target="_blank">Quiz on Variable Declaration and Scope</a></li>
<li><a href="http://www.geeksforgeeks.org/complicated-declarations-in-c/">Complicated declarations in C</a></li>
<li><a title="Permalink to G-Fact 19 (Redeclaration of global variable in C)" href="http://www.geeksforgeeks.org/g-fact-19-redeclaration-of-global-variable-in-c/" rel="bookmark">Redeclaration of global variable in C</a></li>
</ol>
<p style="text-align: center;"><strong><a name="DataTypes"></a>Data Types: </strong></p>
<ol>
<li><a title="Permalink to Data Types in C" href="http://geeksquiz.com/data-types-in-c/">Data Types in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-94/">Use of bool in C</a></li>
<li><a title="Permanent link to Integer Promotions in C" href="http://www.geeksforgeeks.org/integer-promotions-in-c/" rel="bookmark">Integer Promotions in C</a></li>
<li><a href="http://geeksquiz.com/c-language-2/data-types/" target="_blank">Quiz on Data Types in C</a></li>
<li><a title="Permanent link to Comparison of a float with a value in C" href="http://www.geeksforgeeks.org/comparison-float-value-c/" rel="bookmark">Comparison of a float with a value in C</a></li>
</ol>
<p style="text-align: center;"><strong><a name="StorageClasses"></a>Storage Classes: </strong></p>
<ol>
<li><a href="http://geeksquiz.com/storage-classes-in-c/">Storage Classes in C</a></li>
<li><a href="http://geeksquiz.com/static-variables-in-c/">Static Variables in C</a></li>
<li><a href="http://www.geeksforgeeks.org/understanding-extern-keyword-in-c/">Understanding “extern” keyword in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-53/">What are the default values of static variables in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/understanding-volatile-qualifier-in-c/">Understanding “volatile” qualifier in C</a></li>
<li><a href="http://www.geeksforgeeks.org/const-qualifier-in-c/">Const Qualifier in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-80/">Initialization of static variables in C</a></li>
<li><a href="http://www.geeksforgeeks.org/understanding-register-keyword/">Understanding “register” keyword in C</a></li>
<li><a href="http://geeksquiz.com/c-language-2/storage-classes/" target="_blank">Quiz on Storage Classes in C</a></li>
</ol>
<p style="text-align: center;"><strong><a name="InputOutput"></a>Input/Output: </strong></p>
<ol>
<li><a href="http://www.geeksforgeeks.org/g-fact-10/">Returned values of printf() and scanf()</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-11/">What is return type of getchar(), fgetc() and getc() ?</a></li>
<li><a href="http://www.geeksforgeeks.org/scansets-in-c/">Scansets in C</a></li>
<li><a href="http://www.geeksforgeeks.org/puts-vs-printf-for-printing-a-string/">puts() vs printf() for printing a string</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-31/">What is use of %n in printf() ?</a></li>
<li><a href="http://www.geeksforgeeks.org/how-to-print-using-printf/">How to print % using printf()?</a></li>
<li><a href="http://geeksquiz.com/c-language-2/input-and-output/" target="_blank">Quiz on Input Output in C</a></li>
<li><a title="Permanent link to What is the difference between printf, sprintf and fprintf?" href="http://geeksquiz.com/difference-printf-sprintf-fprintf/" rel="bookmark">Difference between printf, sprintf and fprintf?</a></li>
<li><a title="Permanent link to Difference between getc(), getchar(), getch() and getche()" href="http://geeksquiz.com/difference-getchar-getch-getc-getche/" rel="bookmark">Difference between getc(), getchar(), getch() and getche()</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Operators"></a>Operators: </strong></p>
<ol>
<li><a href="http://geeksquiz.com/operators-in-c-set-1-arithmetic-operators/">Introduction to operators in C and Arithmetic Operators</a></li>
<li><a href="http://geeksquiz.com/operators-in-c-set-2-relational-and-logical-operators/">Relational and Logical Operators in C</a></li>
<li><a href="http://www.geeksforgeeks.org/interesting-facts-bitwise-operators-c/" target="_blank">Bitwise Operators in C</a></li>
<li><a href="http://www.geeksforgeeks.org/c-operator-precedence-associativity/">Operator Precedence and Associativity in C</a></li>
<li><a href="http://www.geeksforgeeks.org/evaluation-order-of-operands/">Evaluation order of operands</a></li>
<li><a href="http://www.geeksforgeeks.org/comna-in-c-and-c/">Comma in C and C++</a></li>
<li><a title="Permalink to sizeof operator in C" href="http://geeksquiz.com/sizeof-operator-c/">sizeof operator in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-9/">Operands for sizeof operator</a></li>
<li><a href="http://www.geeksforgeeks.org/a-comma-operator-question/">A comma operator question</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-78/">Result of comma operator as l-value in C and C++</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-74/">Order of operands for logical operators</a></li>
<li><a href="http://www.geeksforgeeks.org/increment-decrement-operators-require-l-value-expression/">Increment (Decrement) operators require L-value Expression</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-59/">Precedence of postfix ++ and prefix ++ in C/C++</a></li>
<li><a href="http://www.geeksforgeeks.org/modulus-on-negative-numbers/">Modulus on Negative Numbers</a></li>
<li><a href="http://www.geeksforgeeks.org/cc-ternary-operator-some-interesting-observations/">C/C++ Ternary Operator – Some Interesting Observations</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-40/">Pre-increment (or pre-decrement) in C++</a></li>
<li><a href="http://www.geeksforgeeks.org/difference-between-p-p-and-p/">Difference between ++*p, *p++ and *++p</a></li>
<li><a href="http://www.geeksforgeeks.org/results-of-comparison-operations-in-c-and-c/">Results of comparison operations in C and C++</a></li>
<li><a href="http://www.geeksforgeeks.org/to-find-sum-of-two-numbers-without-using-any-operator/">To find sum of two numbers without using any operator</a></li>
<li><a href="http://www.geeksforgeeks.org/sequence-points-in-c-set-1/">Sequence Points in C</a></li>
<li><a title="Permalink to Execution of printf with ++ operators" href="http://www.geeksforgeeks.org/execution-printf-operators/" rel="bookmark">Execution of printf with ++ operators</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Preprocessor"></a>Preprocessor</strong>:</p>
<ol>
<li><a href="http://www.geeksforgeeks.org/write-a-c-macro-printx-which-prints-x/">Write a C macro PRINT(x) which prints x</a></li>
<li><a href="http://www.geeksforgeeks.org/variable-length-arguments-for-macros/">Variable length arguments for Macros</a></li>
<li><a href="http://www.geeksforgeeks.org/multiline-macros-in-c/">Multiline macros in C</a></li>
<li><a href="http://www.geeksforgeeks.org/crash-macro-interpretation/">CRASH() macro – interpretation</a></li>
<li><a href="http://www.geeksforgeeks.org/the-offsetof-macro/">The OFFSETOF() macro, </a></li>
<li><a href="http://www.geeksforgeeks.org/branch-prediction-macros-in-gcc/">Branch prediction macros in GCC</a></li>
<li><a title="Permanent link to Diffference between #define and const in C?" href="http://geeksquiz.com/diffference-define-const-c/" rel="bookmark">Diffference between #define and const in C?</a></li>
<li><a title="Permalink to A C Programming Language Puzzle" href="http://www.geeksforgeeks.org/a-c-puzzle/" rel="bookmark">A C Programming Language Puzzle</a></li>
<li><a title="Permalink to What’s difference between header files “stdio.h” and “stdlib.h” ?" href="http://geeksquiz.com/whats-difference-between-and/" rel="bookmark">What’s difference between header files “stdio.h” and “stdlib.h” ?</a></li>
<li><a title="Permalink to How to print a variable name in C?" href="http://geeksquiz.com/how-to-print-a-variable-name-in-c/" rel="bookmark">How to print a variable name in C?</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Array&amp;Strings"></a>Arrays &amp; Strings</strong>:</p>
<ol>
<li><a title="Permalink to Arrays in C Language | Set 1 (Introduction)" href="http://geeksquiz.com/arrays-in-c-language-set-1-introduction/" rel="bookmark">Introduction to Arrays in C Language</a></li>
<li><a href="http://geeksquiz.com/arrays-in-c-language-set-2-interesting-array-properties/">Properties of array in C Language</a></li>
<li><a href="http://www.geeksforgeeks.org/using-sizof-operator-with-array-paratmeters/">Do not use sizeof for array parameters</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-92/">Initialization of variables sized arrays in C</a></li>
<li><a href="http://www.geeksforgeeks.org/are-array-members-deeply-copied/">Are array members deeply copied?</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact/">What is the difference between single quoted and double quoted declaration of char array?</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-44/">Initialization of a multidimensional arrays in C/C++</a></li>
<li><a href="http://www.geeksforgeeks.org/write-one-line-functions-for-strcat-and-strcmp/">Write one line functions for strcat() and strcmp()</a></li>
<li><a href="http://geeksquiz.com/whats-difference-between-char-s-and-char-s-in-c/">What’s difference between char s[] and char *s in C</a></li>
<li><a href="http://www.geeksforgeeks.org/gets-is-risky-to-use/">gets() is risky to use!</a></li>
<li><a href="http://www.geeksforgeeks.org/swap-strings-in-c/">C function to Swap strings, </a></li>
<li><a href="http://www.geeksforgeeks.org/storage-for-strings-in-c/">Storage for Strings in C</a></li>
<li><a href="http://www.geeksforgeeks.org/difference-pointer-array-c/" target="_blank">Difference between array and pointer</a></li>
<li><a title="Permanent link to How to dynamically allocate a 2D array in C?" href="http://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/" rel="bookmark">How to dynamically allocate a 2D array in C?</a></li>
<li><a title="Permanent link to How to pass a 2D array as a parameter in C?" href="http://www.geeksforgeeks.org/pass-2d-array-parameter-c/" rel="bookmark">How to pass a 2D array as a parameter in C?</a></li>
<li><a title="Permalink to How to write long strings in Multi-lines C/C++?" href="http://geeksquiz.com/how-to-write-long-strings-in-multi-lines-cc/" rel="bookmark">How to write long strings in Multi-lines C/C++?</a></li>
<li><a title="Permalink to What are the data types for which it is not possible to create an array?" href="http://geeksquiz.com/can-we-have-an-array-of-all-types-in-c/" rel="bookmark">What are the data types for which it is not possible to create an array?</a></li>
<li><a title="Permalink to Variable Length Arrays in C and C++" href="http://www.geeksforgeeks.org/variable-length-arrays-in-c-and-c/" rel="bookmark">Variable Length Arrays in C and C++</a></li>
</ol>
<p style="text-align: center;"><strong><a name="ControlStatements"></a>Control Statements: </strong></p>
<ol>
<li><a href="http://www.geeksforgeeks.org/g-fact-51/">What should be data type of case labels of switch statement in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/for-versus-while/">For Versus While</a></li>
<li><a href="http://www.geeksforgeeks.org/a-nested-loop-puzzle/">A nested loop puzzle</a></li>
<li><a href="http://www.geeksforgeeks.org/interesting-facts-about-switch-statement-in-c/">switch statement in C</a></li>
</ol>
</div>
<div style="width: 50%; float: right;">
<p style="text-align: center;"><strong><a name="Functions"></a>Functions</strong>:</p>
<ol>
<li><a href="http://geeksquiz.com/functions-in-c/">Functions in C</a></li>
<li><a href="http://www.geeksforgeeks.org/importance-of-function-prototype-in-c/">Importance of function prototype in C</a></li>
<li><a href="http://www.geeksforgeeks.org/functions-that-are-executed-before-and-after-main-in-c/">Functions that are executed before and after main() in C</a></li>
<li><a href="http://www.geeksforgeeks.org/return-statement-vs-exit-in-main/">return statement vs exit() in main()</a></li>
<li><a href="http://www.geeksforgeeks.org/how-to-count-variable-numbers-of-arguments-in-c/">How to Count Variable Numbers of Arguments in C?, </a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-20/">What is evaluation order of function parameters in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/does-c-support-function-overloading/">Does C support function overloading?</a></li>
<li><a href="http://www.geeksforgeeks.org/how-can-i-return-multiple-values-from-a-function/">How can we return multiple values from a function?</a></li>
<li><a href="http://www.geeksforgeeks.org/what-is-the-purpose-of-a-function-prototype/">What is the purpose of a function prototype?</a></li>
<li><a href="http://www.geeksforgeeks.org/what-are-static-functions-in-c/">Static functions in C</a></li>
<li><a href="http://www.geeksforgeeks.org/understanding-exit-abort-and-assert/">exit(), abort() and assert()</a></li>
<li><a href="http://www.geeksforgeeks.org/implicit-return-type-int-c-language/">Implicit return type int in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-95/">What happens when a function is called before its declaration in C?</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Pointers"></a>Pointers</strong>:</p>
<ol>
<li><a href="http://www.geeksforgeeks.org/pointers-in-c-and-c-set-1-introduction-arithmetic-and-array/">Introduction to pointers in C and C++</a></li>
<li><a href="http://www.geeksforgeeks.org/double-pointer-pointer-pointer-c/">Double Pointer (Pointer to Pointer) in C</a></li>
<li><a href="http://www.geeksforgeeks.org/why-c-treats-array-parameters-as-pointers/">Why C treats array parameters as pointers?</a></li>
<li><a href="http://www.geeksforgeeks.org/dereference-reference-dereference-reference/">Output of the program | Dereference, Reference, Dereference, Reference</a></li>
<li><a title="Permalink to Dangling, Void , Null and Wild Pointers" href="http://www.geeksforgeeks.org/dangling-void-null-wild-pointers/" rel="bookmark">Dangling, Void , Null and Wild Pointers</a></li>
<li><a href="http://www.geeksforgeeks.org/an-uncommon-representation-of-array-elements/">An Uncommon representation of array elements</a></li>
<li><a href="http://www.geeksforgeeks.org/how-to-declare-a-pointer-to-a-function/">How to declare a pointer to a function?</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-5/">Pointer vs Array in C</a></li>
<li><a title="Permanent link to void pointer in C" href="http://geeksquiz.com/void-pointer-c/" rel="bookmark">void pointer in C</a></li>
<li><a title="Permalink NULL pointer in C !" href="http://geeksquiz.com/few-bytes-on-null-pointer-in-c/" rel="bookmark">NULL pointer in C !</a></li>
<li><a title="Permanent link to Function Pointer in C" href="http://www.geeksforgeeks.org/function-pointer-in-c/" rel="bookmark">Function Pointer in C</a></li>
<li><a href="http://geeksquiz.com/what-are-near-far-and-huge-pointers/">near, far and huge pointers</a></li>
<li><a title="Permanent link to Generic Linked List in C" href="http://www.geeksforgeeks.org/generic-linked-list-in-c-2/" rel="bookmark">Generic Linked List in C</a></li>
</ol>
<p style="text-align: center;"><a name="EnumStructandUnion"></a><strong>Enum, Struct and Union</strong>:</p>
<ol>
<li><a href="http://geeksquiz.com/enumeration-enum-c/" target="_blank">Enum in C</a></li>
<li><a title="Permanent link to Structures in C" href="http://geeksquiz.com/structures-c/" rel="bookmark">Structures in C</a></li>
<li><a href="http://geeksquiz.com/union-c/" target="_blank">Union in C</a></li>
<li><a href="http://www.geeksforgeeks.org/struct-hack/">Struct Hack</a></li>
<li><a href="http://www.geeksforgeeks.org/structure-member-alignment-padding-and-data-packing/">Structure Member Alignment, Padding and Data Packing</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-68/">Operations on struct variables in C</a></li>
<li><a href="http://www.geeksforgeeks.org/bit-fields-c/">Bit Fields in C</a></li>
<li><a title="Permalink to Structure Sorting (By Multiple Rules) in C++" href="http://www.geeksforgeeks.org/structure-sorting-in-c/" rel="bookmark">Structure Sorting (By Multiple Rules) in C++</a></li>
</ol>
<p style="text-align: center;"><strong><a name="MemoryManagement"></a>Memory Management</strong>:</p>
<ol>
<li><a href="http://www.geeksforgeeks.org/memory-layout-of-c-program/">Memory Layout of C Programs,</a></li>
<li><a href="http://www.geeksforgeeks.org/how-to-deallocate-memory-without-using-free-in-c/">How to deallocate memory without using free() in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/calloc-versus-malloc/">calloc() versus malloc()</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-88/">How does free() know the size of memory to be deallocated?</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-66/">Use of realloc()</a></li>
<li><a href="http://www.geeksforgeeks.org/what-is-memory-leak-how-can-we-avoid/">What is Memory Leak? How can we avoid?</a></li>
</ol>
<p style="text-align: center;"><strong><a name="FileHandling"></a>File Handling</strong>:</p>
<ol>
<li><a href="http://www.geeksforgeeks.org/g-fact-82/">fseek() vs rewind() in C</a></li>
<li><a href="http://www.geeksforgeeks.org/eof-and-feof-in-c/">EOF, getc() and feof() in C</a></li>
<li><a href="http://www.geeksforgeeks.org/fopen-for-an-existing-file-in-write-mode/" target="_blank">fopen() for an existing file in write mode</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Puzzles"></a>Puzzles</strong>:</p>
<ol>
<li><a href="http://geeksquiz.com/c-program-to-print-numbers-from-1-to-n-without-using-semicolon/">C Program to print numbers from 1 to N without using semicolon?</a></li>
<li><a href="http://www.geeksforgeeks.org/to-find-sum-of-two-numbers-without-using-any-operator/">How to find sum of two numbers without using any operator</a></li>
<li><a href="http://www.geeksforgeeks.org/how-will-you-show-memory-representation-of-c-variables/">How will you show memory representation of C variables?</a></li>
<li><a href="http://www.geeksforgeeks.org/condition-to-print-helloword/">Condition To Print “HelloWord”</a></li>
<li><a href="http://www.geeksforgeeks.org/changeadd-only-one-character-and-print-exactly-20-times/">Change/add only one character and print ‘*’ exactly 20 times</a></li>
<li><a href="http://www.geeksforgeeks.org/how-can-we-sum-the-digits-of-a-given-number-in-single-statement/">How can we sum the digits of a given number in single statement?</a></li>
<li><a href="http://www.geeksforgeeks.org/what-is-the-best-way-in-c-to-convert-a-number-to-a-string/">What is the best way in C to convert a number to a string?</a></li>
<li><a href="http://www.geeksforgeeks.org/calculate-logn-in-one-line/">Calculate Logn in one line</a></li>
<li><a href="http://www.geeksforgeeks.org/even-or-odd-without-using-condtional-statement/">Print “Even” or “Odd” without using Conditional statement</a></li>
<li><a href="http://www.geeksforgeeks.org/how-will-you-print-numbers-from-1-to-200-without-using-loop/">How will you print numbers from 1 to 100 without using loop?</a></li>
<li><a href="http://www.geeksforgeeks.org/how-can-we-sum-the-digits-of-a-given-number-in-single-statement/">How can we sum the digits of a given number in single statement?</a></li>
<li><a href="http://www.geeksforgeeks.org/write-a-c-program-to-print-geeks-for-geeks-without-using-a-semicolon/">How will you print “Geeks for Geeks” without using a semicolon</a></li>
<li><a href="http://www.geeksforgeeks.org/write-a-c-function-to-round-floating-point-numbers/">Write a one line C function to round floating point numbers</a></li>
<li><a href="http://www.geeksforgeeks.org/implement-your-own-sizeof/">How will implement Your Own sizeof</a></li>
<li><a href="http://www.geeksforgeeks.org/count-set-bits-floating-point-number/">How to count set bits in a floating point number in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/c-puzzle/">How to change the output of printf() in main() ?</a></li>
<li><a href="http://www.geeksforgeeks.org/find-length-string-without-strlen-loop/">How to find length of a string without string.h and loop in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/implement-itoa/">Implement your own itoa()</a></li>
<li><a href="http://www.geeksforgeeks.org/write-a-c-program-that-doesnt-terminate-when-ctrlc-is-pressed/">Write a C program that does not terminate when Ctrl+C is pressed</a></li>
<li><a href="http://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/">How to measure time taken by a function in C?</a></li>
<li><a href="http://www.geeksforgeeks.org/print-long-int-number-c-using-putchar/" target="_blank">Print a long int in C using putchar() only</a></li>
<li><a title="Permanent link to Convert a floating point number to string in C" href="http://www.geeksforgeeks.org/convert-floating-point-number-string/" rel="bookmark">Convert a floating point number to string in C</a></li>
<li><a title="Permanent link to How to write a running C code without main()?" href="http://www.geeksforgeeks.org/write-running-c-code-without-main/" rel="bookmark">How to write a running C code without main()?</a></li>
<li><a title="Permanent link to Write your own memcpy()" href="http://www.geeksforgeeks.org/write-memcpy/" rel="bookmark">Write your own memcpy()</a></li>
</ol>
<p style="text-align: center;"><strong><a name="Misc"></a>Misc</strong>:</p>
<ol>
<li><a href="http://www.geeksforgeeks.org/quine-a-self-reproducing-program/">Quine – A self-reproducing program</a></li>
<li><a href="http://www.geeksforgeeks.org/complicated-declarations-in-c/">Complicated declarations in C</a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-94/">Use of bool in C</a></li>
<li><a href="http://www.geeksforgeeks.org/sequence-points-in-c-set-1/">Sequence Points in C | Set 1</a></li>
<li><a href="http://www.geeksforgeeks.org/optimization-techniques-set-2-swapping/">Optimization Techniques | Set 2 (swapping), </a></li>
<li><a href="http://www.geeksforgeeks.org/g-fact-72/">ASCII NUL, ASCII 0 (’0?) and Numeric literal 0</a></li>
<li><a href="http://www.geeksforgeeks.org/little-and-big-endian-mystery/">Little and Big Endian Mystery, </a></li>
<li><a href="http://www.geeksforgeeks.org/comparator-function-of-qsort-in-c/">Comparator function of qsort() in C</a></li>
<li><a href="http://www.geeksforgeeks.org/program-to-validate-an-ip-address/">Program to validate an IP address</a></li>
<li><a title="Permanent link to Multithreading in C" href="http://www.geeksforgeeks.org/multithreading-c-2/" rel="bookmark">Multithreading in C</a></li>
<li><a title="Permanent link to Assertions in C/C++" href="http://geeksquiz.com/assertions-cc/" rel="bookmark">Assertions in C/C++</a></li>
<li><a href="http://geeksquiz.com/fork-system-call/">fork() in C</a></li>
<li><a title="Permalink to Interesting Facts in C Programming" href="http://www.geeksforgeeks.org/interesting-facts-in-c-programming/" rel="bookmark">Interesting Facts in C Programming</a></li>
<li><a title="Permalink to Precision of floating point numbers in C++ (floor(), ceil(), trunc(), round() and setprecision())" href="http://www.geeksforgeeks.org/precision-of-floating-point-numbers-in-c-floor-ceil-trunc-round-and-setprecision/" rel="bookmark">Precision of floating point numbers in C++ (floor(), ceil(), trunc(), round() and setprecision())</a></li>
</ol>
<p style="text-align: center;"><strong><a name="CLanguageInterviewQuestions"></a>C Language Interview Questions </strong></p>
<li><a title="Permanent link to Commonly Asked C Programming Interview Questions | Set 1" href="http://geeksquiz.com/commonly-asked-c-programming-interview-questions-set-1/" rel="bookmark">Commonly Asked C Programming Interview Questions | Set 1</a></li>
<li><a title="Permanent link to Commonly Asked C Programming Interview Questions | Set 2" href="http://geeksquiz.com/commonly-asked-c-programming-interview-questions-set-2/" rel="bookmark">Commonly Asked C Programming Interview Questions | Set 2</a></li>
</ol>
</div>
<p>&nbsp;<br />
&nbsp;<br />
&nbsp;<br />
<strong><a href="http://www.geeksforgeeks.org/cc-programs/" target="_blank">C/C++ Programs</a></strong></p>
<p><a href="http://www.practice.geeksforgeeks.org/">Coding Practice Platform</a></p>
<p>&nbsp;</p>
			
<div class="AdsParent" style="width:100%;margin-top:30px;">
<span class="rectangleAd">
<!--
<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
 Big Rectangle Blog Bottom 
<ins class="adsbygoogle"
     style="display:inline-block;width:336px;height:280px"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="4061219431"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>
-->
<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- GfGDownLeftNew -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="5794942435"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>
</span>
<span class="responsiveAd">
<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- newMobile2 -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="1950485631"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>
</span>
</div>

<h1><strong><a href="http://practice.geeksforgeeks.org/company-tags">Company Wise Coding Practice</a>
&nbsp;&nbsp;&nbsp;<a href="http://practice.geeksforgeeks.org/topic-tags">Topic Wise Coding Practice</a></strong></h1>



		</div><!-- .entry-content -->
		<footer class="entry-meta">
					</footer><!-- .entry-meta -->
	</article><!-- #post -->
	<footer class="entry-meta">
	

	<div id="share-buttons" style="display:none">
   
    <!-- Facebook -->
    <a href="http://www.facebook.com/sharer.php?u=http://www.geeksforgeeks.org/c/" target="_blank" title="Share on Facebook">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/facebook.png" alt="Facebook" />
    </a>
    
    <!-- Google+ -->
    <a href="https://plus.google.com/share?url=http://www.geeksforgeeks.org/c/" target="_blank" title="Share on Google">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/google.png" alt="Google" />
    </a>
    
    <!-- LinkedIn -->
    <a href="http://www.linkedin.com/shareArticle?mini=true&amp;url=http://www.geeksforgeeks.org/c/" target="_blank" title="Share on LinkedIn">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/linkedin.png" alt="LinkedIn" />
    </a>
    
    <!-- Twitter -->
    <a href="https://twitter.com/share?url=http://www.geeksforgeeks.org/c/&amp;text=C Programming Language&amp;hashtags=GeeksforGeeks" target="_blank" title="Share on Twitter">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/twitter.png" alt="Twitter" />
    </a>

    <!-- Pinterest -->
    <a href="javascript:void((function()%7Bvar%20e=document.createElement('script');e.setAttribute('type','text/javascript');e.setAttribute('charset','UTF-8');e.setAttribute('src','http://assets.pinterest.com/js/pinmarklet.js?r='+Math.random()*99999999);document.body.appendChild(e)%7D)());" title="Share on Pinterest">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/pinterest.png" alt="Pinterest" />
    </a>
    
    <!-- Reddit -->
    <a href="http://reddit.com/submit?url=http://www.geeksforgeeks.org/c/&amp;title=C Programming Language" target="_blank" title="Share on Reddit">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/reddit.png" alt="Reddit" />
    </a>
    
    <!-- StumbleUpon-->
    <a href="http://www.stumbleupon.com/submit?url=http://www.geeksforgeeks.org/c/&amp;title=C Programming Language" target="_blank" title="Share on StumbleUpon">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/stumbleupon.png" alt="StumbleUpon" />
    </a>
    
    <!-- Tumblr-->
    <a href="http://www.tumblr.com/share/link?url=http://www.geeksforgeeks.org/c/&amp;title=C Programming Language" target="_blank" title="Share on Tumblr">
        <img src="http://www.geeksforgeeks.org/wp-content/uploads/tumblr.png" alt="Tumblr" />
    </a>
   
	</div>

	<br></br>
	<p>Writing code in comment? Please use <a href="http://ide.geeksforgeeks.org/">ide.geeksforgeeks.org</a>, generate link and share the link here.</a></p>
	<br/>
	<div style="display:flex">
		<button id="comment" class="action-button" style="width:45%;cursor: pointer;margin-right:10%;box-shadow: 0 2px 5px 0 rgba(0,0,0,0.4), 0 6px 20px 0 rgba(0,0,0,0);border-color: #4cb96b;border-radius: 4px;">Load Comments</button>
		<button id="share" class="action-button" onclick="document.getElementById('share-buttons').style.display='block';this.style.display='none';" style="width:45%;cursor: pointer;margin-right:10%;box-shadow: 0 2px 5px 0 rgba(0,0,0,0.4), 0 6px 20px 0 rgba(0,0,0,0);border-color: #4cb96b;border-radius: 4px;">Share this post !</button>

	</div>

        <div id="disqus_thread"></div>

					</div><!-- #content -->
	</div><!-- #primary -->

	<script>jQuery(document).ready(function($){$('#comment').on('click',function(){$.ajax({type:"GET",url:"http://geeksforgeeks.disqus.com/embed.js",dataType:"script",cache:!0});$(this).fadeOut()});if(window.location.href.indexOf('#comment') > -1){jQuery('#comment').click();}});</script>

<style type="text/css">
 
#share-buttons img {
width: 35px;
padding: 5px;
border: 0;
box-shadow: 0;
display: inline;
}
#share-buttons a:hover {
	text-decoration: none;
}
</style>

			<div id="secondary" class="widget-area" role="complementary">
			<aside id="text-33" class="widget widget_text">			<div class="textwidget"><script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Big 300x600 Sidebar -->
<ins class="adsbygoogle"
     style="display:inline-block;width:300px;height:600px"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="4402736037"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script></div>
		</aside><aside id="text-40" class="widget widget_text">			<div class="textwidget"><div class="trendings_gfg_hard_code">
    <table width="100%" align="center">
        <thead>
            <tr>
                <th style="border:1px solid #6AA84F;background-color:#4CB96B;color:#fff;text-align: center;font-size: 16px;">Trending Content</th>
            </tr>
        </thead>
        <tbody>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/implementing-our-own-hash-table-with-separate-chaining-in-java/">Implementing our Own Hash Table with Separate Chaining in Java</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/print-binary-tree-vertical-order/">Print a Binary Tree in Vertical Order | Set 1</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/find-the-k-most-frequent-words-from-a-file/">Find the k most frequent words from a file</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/amazon-interview-experience-set-161-off-campus-sde-1-banglore/">Amazon Interview Experience | Set 161 (Off Campus for SDE-1, Banglore)</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/">Median of two sorted arrays of different sizes</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/qa-placement-quizzes-algebra-question-10/">QA – Placement Quizzes | Algebra | Question 10</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/amazon-interview-experience-set-339-sde-2/">Amazon Interview Experience | Set 339 (For SDE 2)</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/gate-gate-cs-2013-question-6/">GATE | GATE CS 2013 | Question 6</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/">Print Ancestors of a given node in Binary Tree</a>			                </td>
			            </tr>
        	        	  		<tr>
			                <td style="border:1px solid #6AA84F;padding:2px;">
			                    <a href="http://www.geeksforgeeks.org/pattern-searching-set-8-suffix-tree-introduction/">Pattern Searching | Set 8 (Suffix Tree Introduction)</a>			                </td>
			            </tr>
        	        </tbody>
    </table>
</div></div>
		</aside><aside id="text-41" class="widget widget_text">			<div class="textwidget"><a href="http://www.geeksforgeeks.org/progeek-cup-1-0-project-competition-geeksforgeeks/" style="margin-right: 0px !important;">
  <center>
    <input type="button" value="ProGeek Cup 1.0" style="background-color: #4cb96b; color:white; width:100%; font-size:large; cursor:pointer;font-weight:bold;">
  </center>
</a></div>
		</aside><aside id="text-18" class="widget widget_text">			<div class="textwidget"><script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- ResponsiveRightBarMay16 -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="7089558833"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script></div>
		</aside><aside id="text-14" class="widget widget_text">			<div class="textwidget"><table align="center" width="100%">
    <thead>
        <tr>
            <th style="border:1px solid #6AA84F;background-color:#4CB96B;color:#fff;text-align: center;font-size: 16px;line-height:1.7;">
                Most Visited Posts
            </th>
        </tr>
    </thead>
    <tbody>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/top-algorithms-and-data-structures-for-competitive-programming/">Top 10 Algorithms and Data Structures for Competitive Programming</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/top-10-algorithms-in-interview-questions/">Top 10 algorithms in Interview Questions</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/how-to-begin-with-competitive-programming/">How to begin with Competitive Programming?</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/a-complete-step-by-step-guide-for-placement-preparation-by-geeksforgeeks/">Step by Step Guide for Placement Preparation</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/how-to-prepare-for-acm-icpc/">How to prepare for ACM-ICPC?</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://quiz.geeksforgeeks.org/insertion-sort/">Insertion Sort</a>,
                <a href="http://geeksquiz.com/binary-search/">Binary Search</a>,
                <a href="http://geeksquiz.com/quick-sort/">QuickSort</a>,
                <a href="http://geeksquiz.com/merge-sort/">MergeSort</a>,
                <a href="http://geeksquiz.com/heap-sort/">HeapSort</a>
            </td>
        </tr>
    </tbody>
</table></div>
		</aside><aside id="text-36" class="widget widget_text">			<div class="textwidget"><script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- GfGSideBottomResponsive -->
<ins class="adsbygoogle"
     style="display:block"
     data-ad-client="ca-pub-9465609616171866"
     data-ad-slot="5749413230"
     data-ad-format="auto"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script></div>
		</aside><aside id="text-42" class="widget widget_text">			<div class="textwidget"><!-- BuySellAds Zone Code -->
<div id="bsap_1306934" class="bsarocks bsap_785bf45b162de1c5511e8baa02854e5c"></div>
<!-- End BuySellAds Zone Code --></div>
		</aside><aside id="text-13" class="widget widget_text">			<div class="textwidget"><table align="center" width="100%">
    <thead>
        <tr>
            <th style="border:1px solid #6AA84F;background-color:#4CB96B;color:#fff;text-align: center;font-size: 16px;line-height:1.7;">
                Popular Categories
            </th>
        </tr>
    </thead>
    <tbody>

        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/interview-experiences/">Interview Experiences</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/advanced-data-structures/">Advanced Data Structures</a>
            </td>
        </tr>

        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/dynamic-programming/">Dynamic Programming</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/greedy/">Greedy Algorithms</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/backtracking/">Backtracking</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/pattern-searching/">Pattern Searching</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/divide-and-conquer/">Divide &amp; Conquer</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/algorithm/geometric/">Geometric Algorithms</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/searching/">Searching</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/sorting/">Sorting</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/algorithm/analysis/">Analysis of Algorithms</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/algorithm/mathematical/">Mathematical Algorithms</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/algorithm/randomized/">Randomized Algorithms</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/tag/recursion">Recursion</a>
            </td>
        </tr>
        <tr>
            <td style="border:1px solid #6AA84F;padding:2px;line-height:1.7;font-size:13px;">
                <a href="http://www.geeksforgeeks.org/category/algorithm/game-theory/">Game Theory</a>
            </td>
        </tr>

    </tbody>
</table></div>
		</aside><aside id="tag_cloud-3" class="widget widget_tag_cloud"><p class="widget-title">Tags</p><div class="tagcloud"><a href='http://www.geeksforgeeks.org/category/advanced-data-structure/' class='tag-link-1762 tag-link-position-1' title='130 topics' style='font-size: 10.820895522388pt;'>Advanced Data Structure</a>
<a href='http://www.geeksforgeeks.org/tag/amazon/' class='tag-link-1942 tag-link-position-2' title='379 topics' style='font-size: 15.626865671642pt;'>Amazon</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/aptitude-gq/' class='tag-link-2200 tag-link-position-3' title='202 topics' style='font-size: 12.805970149254pt;'>Aptitude</a>
<a href='http://www.geeksforgeeks.org/tag/aptitude/' class='tag-link-2159 tag-link-position-4' title='202 topics' style='font-size: 12.805970149254pt;'>Aptitude</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/c-arrays/' class='tag-link-3 tag-link-position-5' title='328 topics' style='font-size: 15pt;'>Arrays</a>
<a href='http://www.geeksforgeeks.org/category/algorithm/bit-magic/' class='tag-link-17 tag-link-position-6' title='122 topics' style='font-size: 10.507462686567pt;'>Bit Magic</a>
<a href='http://www.geeksforgeeks.org/category/programming-language/c/' class='tag-link-2064 tag-link-position-7' title='436 topics' style='font-size: 16.253731343284pt;'>C</a>
<a href='http://www.geeksforgeeks.org/tag/c/' class='tag-link-2138 tag-link-position-8' title='399 topics' style='font-size: 15.835820895522pt;'>C</a>
<a href='http://www.geeksforgeeks.org/category/programming-language/cpp/' class='tag-link-2065 tag-link-position-9' title='418 topics' style='font-size: 16.044776119403pt;'>C++</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/computer-science-quizzes-gq/cpp-gq/' class='tag-link-2207 tag-link-position-10' title='130 topics' style='font-size: 10.820895522388pt;'>C++ Quiz</a>
<a href='http://www.geeksforgeeks.org/tag/cpp-library/' class='tag-link-1964 tag-link-position-11' title='84 topics' style='font-size: 8.8358208955224pt;'>CPP-Library</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/computer-science-quizzes-gq/c-gq/' class='tag-link-2206 tag-link-position-12' title='274 topics' style='font-size: 14.164179104478pt;'>C Quiz</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/computer-science-quizzes-gq/data-structures-gate-gq/' class='tag-link-2213 tag-link-position-13' title='129 topics' style='font-size: 10.716417910448pt;'>Data Structures</a>
<a href='http://www.geeksforgeeks.org/tag/data-structures/' class='tag-link-2142 tag-link-position-14' title='129 topics' style='font-size: 10.716417910448pt;'>Data Structures</a>
<a href='http://www.geeksforgeeks.org/category/computer-subject/dbms/' class='tag-link-2053 tag-link-position-15' title='92 topics' style='font-size: 9.2537313432836pt;'>DBMS</a>
<a href='http://www.geeksforgeeks.org/category/algorithm/dynamic-programming/' class='tag-link-1746 tag-link-position-16' title='208 topics' style='font-size: 12.910447761194pt;'>Dynamic Programming</a>
<a href='http://www.geeksforgeeks.org/category/interview-experiences/experienced-interview-experiences/' class='tag-link-1795 tag-link-position-17' title='95 topics' style='font-size: 9.3582089552239pt;'>Experienced</a>
<a href='http://www.geeksforgeeks.org/tag/gate-cs-2012/' class='tag-link-133 tag-link-position-18' title='75 topics' style='font-size: 8.3134328358209pt;'>GATE-CS-2012</a>
<a href='http://www.geeksforgeeks.org/category/guestblogs/' class='tag-link-1710 tag-link-position-19' title='170 topics' style='font-size: 11.970149253731pt;'>GBlog</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/graph/' class='tag-link-2068 tag-link-position-20' title='152 topics' style='font-size: 11.44776119403pt;'>Graph</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/hash/' class='tag-link-1756 tag-link-position-21' title='83 topics' style='font-size: 8.7313432835821pt;'>Hash</a>
<a href='http://www.geeksforgeeks.org/category/interview-experiences/internship-interview-experiences/' class='tag-link-1794 tag-link-position-22' title='103 topics' style='font-size: 9.7761194029851pt;'>Internship</a>
<a href='http://www.geeksforgeeks.org/category/interview-experiences/' class='tag-link-1140 tag-link-position-23' title='1,561 topics' style='font-size: 22pt;'>Interview Experiences</a>
<a href='http://www.geeksforgeeks.org/category/programming-language/java/' class='tag-link-2058 tag-link-position-24' title='496 topics' style='font-size: 16.880597014925pt;'>Java</a>
<a href='http://www.geeksforgeeks.org/tag/java/' class='tag-link-2082 tag-link-position-25' title='73 topics' style='font-size: 8.2089552238806pt;'>java-</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/computer-science-quizzes-gq/java-gq/' class='tag-link-2208 tag-link-position-26' title='73 topics' style='font-size: 8.2089552238806pt;'>Java Quiz</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/linked-list/' class='tag-link-8 tag-link-position-27' title='128 topics' style='font-size: 10.716417910448pt;'>Linked Lists</a>
<a href='http://www.geeksforgeeks.org/category/algorithm/mathematical/' class='tag-link-1753 tag-link-position-28' title='414 topics' style='font-size: 16.044776119403pt;'>Mathematical</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/matrix/' class='tag-link-1760 tag-link-position-29' title='138 topics' style='font-size: 11.029850746269pt;'>Matrix</a>
<a href='http://www.geeksforgeeks.org/category/multiple-choice-question/' class='tag-link-66 tag-link-position-30' title='96 topics' style='font-size: 9.4626865671642pt;'>MCQ</a>
<a href='http://www.geeksforgeeks.org/tag/microsoft/' class='tag-link-104 tag-link-position-31' title='130 topics' style='font-size: 10.820895522388pt;'>Microsoft</a>
<a href='http://www.geeksforgeeks.org/tag/number-digits/' class='tag-link-1911 tag-link-position-32' title='70 topics' style='font-size: 8pt;'>number-digits</a>
<a href='http://www.geeksforgeeks.org/category/program-output/' class='tag-link-5 tag-link-position-33' title='99 topics' style='font-size: 9.5671641791045pt;'>Program Output</a>
<a href='http://www.geeksforgeeks.org/category/project/' class='tag-link-1767 tag-link-position-34' title='74 topics' style='font-size: 8.3134328358209pt;'>Project</a>
<a href='http://www.geeksforgeeks.org/category/puzzles/' class='tag-link-2063 tag-link-position-35' title='88 topics' style='font-size: 9.044776119403pt;'>Puzzles</a>
<a href='http://www.geeksforgeeks.org/category/programming-language/python/' class='tag-link-1789 tag-link-position-36' title='226 topics' style='font-size: 13.328358208955pt;'>Python</a>
<a href='http://www.geeksforgeeks.org/category/quizzes-gq/qa-placement-quizzes-gq/' class='tag-link-2204 tag-link-position-37' title='274 topics' style='font-size: 14.164179104478pt;'>QA - Placement Quizzes</a>
<a href='http://www.geeksforgeeks.org/tag/qa-placement-quizzes/' class='tag-link-2187 tag-link-position-38' title='274 topics' style='font-size: 14.164179104478pt;'>QA - Placement Quizzes</a>
<a href='http://www.geeksforgeeks.org/category/school-programming/' class='tag-link-2078 tag-link-position-39' title='203 topics' style='font-size: 12.805970149254pt;'>School Programming</a>
<a href='http://www.geeksforgeeks.org/category/algorithm/searching/' class='tag-link-1751 tag-link-position-40' title='76 topics' style='font-size: 8.4179104477612pt;'>Searching</a>
<a href='http://www.geeksforgeeks.org/category/algorithm/sorting/' class='tag-link-1752 tag-link-position-41' title='151 topics' style='font-size: 11.44776119403pt;'>Sorting</a>
<a href='http://www.geeksforgeeks.org/tag/stl/' class='tag-link-1797 tag-link-position-42' title='92 topics' style='font-size: 9.2537313432836pt;'>STL</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/c-strings/' class='tag-link-7 tag-link-position-43' title='243 topics' style='font-size: 13.641791044776pt;'>Strings</a>
<a href='http://www.geeksforgeeks.org/category/technical-scripter/' class='tag-link-1788 tag-link-position-44' title='85 topics' style='font-size: 8.8358208955224pt;'>Technical Scripter</a>
<a href='http://www.geeksforgeeks.org/category/data-structures/tree/' class='tag-link-19 tag-link-position-45' title='216 topics' style='font-size: 13.119402985075pt;'>Trees</a></div>
</aside><aside id="text-43" class="widget widget_text">			<div class="textwidget"><!-- BuySellAds Zone Code -->
<div id="bsap_1304848" class="bsarocks bsap_785bf45b162de1c5511e8baa02854e5c"></div>
<!-- End BuySellAds Zone Code --></div>
		</aside><aside id="text-32" class="widget widget_text">			<div class="textwidget"><a href="http://www.geeksforgeeks.org/recent-comments/" style="margin-right: 0px !important;">
  <center>
    <input type="button" value="Recent Comments" style="background-color: #4cb96b; color:white; width:100%; font-size:large; cursor:pointer;font-weight:bold;">
  </center>
</a></div>
		</aside>		</div><!-- #secondary -->
		</div><!-- #main .wrapper -->
	<footer id="colophon" role="contentinfo" style="padding:0; ">
		<div class="site-info">
		<div class="clear"></div>
		</div><!-- .site-info -->
		</footer><!-- #colophon -->
<center>
  <div class="iconic-footer" style="min-height:40px;font-size:14px;padding-bottom: 0px;line-height: 1.5;">
    @geeksforgeeks, 
    <a href="http://creativecommons.org/licenses/by-nc-nd/2.5/in/deed.en_US" title="Valid XHTML Strict 1.0">Some rights reserved</a><a href="http://www.geeksforgeeks.org/about/contact-us/"> &nbsp; &nbsp; &nbsp; &nbsp;Contact Us!</a>
    <a href="http://www.geeksforgeeks.org/about/"> &nbsp; &nbsp; &nbsp; &nbsp;About Us!&nbsp; &nbsp; &nbsp;</a>
    <a href="http://www.geeksforgeeks.org/advertise-with-us/"> &nbsp; &nbsp; &nbsp;Advertise with us!&nbsp; &nbsp; </a>
    <a href="http://www.geeksforgeeks.org/privacy-policy/">&nbsp; &nbsp; &nbsp; Privacy Policy&nbsp; &nbsp;&nbsp; </a>
    <!-- adding social buttons on 07 April, 2017 -->
    <a href="https://www.facebook.com/GeeksforGeeks-316764689022/timeline/" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="facebook">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_facebook_green.png" style="width:30px;vertical-align: middle;" />
    </a>
    <a href="https://twitter.com/geeksforgeeks" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="twitter">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_twitter_green.png" style="width:30px;vertical-align: middle;" />
    </a>
    <a href="https://www.linkedin.com/company-beta/1299009" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="linkedin">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_linkedin_green.png" style="width:30px;vertical-align: middle;" />
    </a>
    <a href="https://play.google.com/store/apps/details?id=free.programming.programming" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="play store">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_play_store_green.png" style="width:30px;vertical-align: middle;" />
    </a>
    <a href="https://www.microsoft.com/en-us/store/apps/geeksforgeeks-official/9nblggh4rh30" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="windows store">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_windows_store_green.png" style="width:30px;vertical-align: middle;" />
    </a>
    <a href="https://itunes.apple.com/us/app/geeksforgeeks/id1101205459?ls=1&mt=8" style="display: inline-block;margin-left: 10px;border:1px solid #fff;border-radius: 2px;" title="app store">
      <img src="http://www.geeksforgeeks.org/wp-content/uploads/square_app_store_green.png" style="width:30px;vertical-align: middle;" />
    </a>
  </div>
</center><!-- .site-info -->

				<div class="clear"></div>
</div><!-- #page -->

<script type='text/javascript' src='http://www.geeksforgeeks.org/wp-includes/js/wp-embed.min.js'></script>

<script type="text/javascript">
// below changes to be added in gfg.js in future.
// load comment button click when page scroll to it and positioned ad in mobile view.
flag=0;jQuery(window).scroll(function(){if(jQuery('#comment').length !=0 ){var hT=jQuery('#comment').offset().top,hH=jQuery('#comment').outerHeight(),wH=jQuery(window).height(),wS=jQuery(this).scrollTop();if(wS>(hT+hH-wH-70)&&!flag){jQuery('#comment').click();flag=1}}});var temp_width=jQuery(window).width();if(temp_width<468){if(jQuery('article').length>1){jQuery(jQuery('.responsiveAd')).insertAfter('article:eq(2)');jQuery('.rectangleAd').hide()}
else{jQuery('.responsiveAd').hide();jQuery('.rectangleAd').css('width','')}}


  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-12148232-1']);
  _gaq.push(['_trackPageview']);

  (function() {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();

</script>  
<script async type="text/javascript" src="//cdn.fancybar.net/ac/fancybar.js?zoneid=1502&serve=C6ADVKE&placement=geeksforgeeks" id="_fancybar_js"></script>
</body>
</html>

<!-- Dynamic page generated in 0.144 seconds. -->
<!-- Cached page generated by WP-Super-Cache on 2017-06-13 07:03:26 -->

<!-- Compression = gzip -->
<!-- super cache -->