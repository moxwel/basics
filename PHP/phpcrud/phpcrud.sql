CREATE DATABASE `test`;
USE `test`;

CREATE TABLE `tablatest` (
  `id` int(11) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `apell` varchar(20) NOT NULL,
  `nota` int(11) NOT NULL
);

ALTER TABLE `tablatest`
  ADD PRIMARY KEY (`id`);

ALTER TABLE `tablatest`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
