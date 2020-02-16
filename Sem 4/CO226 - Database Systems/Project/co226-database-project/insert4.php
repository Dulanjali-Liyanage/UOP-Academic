<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */


$link = mysqli_connect("localhost", "root","", "database_project");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}

// Attempt insert query execution
    $menuId =$_GET['menuId'];
   $firstName = $_GET['fname'];
   $lastName = $_GET['lname'];
    $apt = $_GET['apt'];
	$street = $_GET['Street'];
	 $city = $_GET['city'];
	$telNo = $_GET['Telphone'];




$sql = "INSERT INTO Customers (menu_id,firstName, lastName,apt_no,street,city,telephone_no ) VALUES ($menuId,'$firstName', '$lastName', $apt,'$street','$city',$telNo)";


if(mysqli_query($link, $sql)){



} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}

// Close connection
mysqli_close($link);
?>
<html>
<body>
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<style>
body{
   background-image: url('../images/img8.jpg');
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   margin-left:50px;
   margin-top:40px;
   }

</style>

<h1>You have reserved your meal successfully...</h1>

<p> Thank you,We'll deliver your meal as soon as possible...
</p>

<a href="index.html">
<input type="button" name="Backtohome" value="Back to home"></a>

<a href="customerDetails.html">
<input type="button" name="Backtoapplication" value="Back to application"></a>

</body>
</html>
