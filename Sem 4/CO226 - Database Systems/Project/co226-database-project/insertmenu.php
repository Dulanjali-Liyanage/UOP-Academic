
<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "database_project");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
   $name1 =$_GET['menu_id'];
   $name2 =$_GET['menu_name'];
   $name3 =$_GET['price'];
   $name4 =$_GET['aval'];




// Attempt insert query execution
$sql = "INSERT INTO Menu (menu_id,name,price,availability) VALUES($name1,'$name2',$name3,'$name4')";





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
   background-image: url('../images2/img8.jpg');
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   }

</style>

<h1>Menu is updated  successfully...</h1>

<p> Thank you..
</p>

<a href="menuView.html">
<input type="button" name="Backtohome" value="Back to Menu View"></a>

</body>
</html>
