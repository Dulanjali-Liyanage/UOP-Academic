<html>
<style>

#margin{

     margin: 10px;
     border: 3px solid black;
     padding: 10px;
	 width: 500px;
	 height:500px;}
	}
	 
</style>
<div id="margin">
<body>


<h1><b>Your Information System</b></h1>

Thank you, <?php echo $_POST["firstName"]?> for your perches from our web site<br><br>
your item colour is : <?php echo $_POST["colors"] ?> & T-Shirt size :<?php echo $_POST["x"] ?><br><br>
Selected items/items are:
<br>
<ul>
<?php 

	if(!empty($_POST["item"])){
		foreach($_POST["item"] as $item){ 
			echo "*".$item."<br>";
		}
	}
	

?>
</ul>


your items will be send to:<br><br>
<?php echo "<i>". $_POST["firstName"]."</i>"?> <?php echo "<i>".$_POST["lastName"]."</i>" ?>,<br>
<?php echo "<i>".$_POST["address1"]."</i>" ?>,<br>
<?php echo "<i>".$_POST["address2"]."</i>"?>,<br>
<?php echo "<i>".$_POST["address3"]."</i>"?><br><br>


 
 <?php
 if(!empty($_POST["yourComments"])){
    echo "Thank you for submitting your comments.We appriciate it.You said:";
	echo "<br>";
	echo "<br>";
	echo "<i>";
	echo  $_POST["yourComments"];
	echo "</i>";
 }?>
	
</body>
</div>
</html>