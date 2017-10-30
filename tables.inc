<?php
class Table {
   var $data;
   var $type;
   /*
    0: normal table (no link)
    1: actor table
    2: movie table
   */

   function __construct($data, $type=0) {
       $this->data = $data;
       $this->type = $type;
       $this->create();
   }

   function create() {
     $result = $this->data;
     $type = $this->type;
    //  print $type;

     print "<table>";

     print "<tr>";
     for($i = 0; $i < mysql_num_fields($result); $i++) {
         $field_info = mysql_fetch_field($result, $i);
         echo "<th>{$field_info->name}</th>";
     }
     print "</tr>";

     while($row = mysql_fetch_row($result)) {
       print "<tr>";
       $id = $row[0];
       for($i = 0; $i < count($row); $i++) {
         switch($type) {
           case 0:
             print "<th>$row[$i]</th>"; break;
           case 1:
             print "<th><a href='Show_A.php?id={$id}'>$row[$i]</a></th>"; break;
           case 2:
             print "<th><a href='Show_M.php?id={$id}'>$row[$i]</a></th>"; break;
           default:
             print "table type error!"; break;
         }
       }
       print "</tr>";
     }
     print "</table>";
     print "<br>";
   }

}
?>