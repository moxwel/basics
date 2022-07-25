CREATE DATABASE txtdb;
USE txtdb;

CREATE TABLE `datos` (
  `id` int(11) NOT NULL,
  `nom` varchar(20) NOT NULL,
  `nom2` varchar(20) NOT NULL,
  `nota` int(11) NOT NULL DEFAULT 0
);

ALTER TABLE `datos`
  ADD PRIMARY KEY (`id`),
  ADD UNIQUE KEY (`nom`);

ALTER TABLE `datos`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT;
