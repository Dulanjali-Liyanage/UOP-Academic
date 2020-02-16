
<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "database_project");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
	$name1 = $_GET['empssn'];

   	$name2 =$_GET['selecter'];


   	$name3 =$_GET['search_by'];

// Attempt insert query execution
$sql = "update Employee set $name2 = '$name3' where Ssn = $name1";



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
   background-image: url('../images/img9.jpg');
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   margin-left:50px;
   margin-top:40px;
   }


</style>

<h1>You have updated your data successfully...</h1>

<br>
<br>
<br>


<a href="index.html">
<input type="button" name="Backtohome" value="Back to home"></a>

<a href="empSearchUpdate.html">
<input type="button" name="Backtoapplication" value="Back to application"></a>

</body>
</html>
