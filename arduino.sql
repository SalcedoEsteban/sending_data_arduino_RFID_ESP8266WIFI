-- phpMyAdmin SQL Dump
-- version 4.7.9
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 11-03-2019 a las 00:30:03
-- Versión del servidor: 5.7.18-log
-- Versión de PHP: 7.2.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `arduino`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `tarjeta`
--

CREATE TABLE `tarjeta` (
  `tar_id` int(11) NOT NULL,
  `tar_chi_id` varchar(45) NOT NULL,
  `tar_cod` varchar(40) DEFAULT NULL,
  `tar_fec` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Volcado de datos para la tabla `tarjeta`
--

INSERT INTO `tarjeta` (`tar_id`, `tar_chi_id`, `tar_cod`, `tar_fec`) VALUES
(1, '124523', '1234', '2019-03-09 00:01:35'),
(2, '333971', '', '2019-03-09 00:05:12'),
(3, '333971', '', '2019-03-09 00:05:13'),
(4, '333971', '', '2019-03-09 00:05:18'),
(5, '333971', '', '2019-03-09 00:05:24'),
(6, '333971', '', '2019-03-09 00:05:29'),
(7, '333971', '', '2019-03-09 00:05:35'),
(8, '333971', '', '2019-03-09 00:05:40'),
(9, '333971', '5025123116', '2019-03-09 00:05:45'),
(10, '333971', '5025123116', '2019-03-09 00:05:51'),
(11, '333971', '5025123116', '2019-03-09 00:05:56'),
(12, '333971', '5025123116', '2019-03-09 00:06:02'),
(13, '333971', '50251231165025123116', '2019-03-09 00:06:07'),
(14, '333971', '50251231165025123116', '2019-03-09 00:06:12'),
(15, '333971', '50251231165025123116', '2019-03-09 00:06:18'),
(16, '333971', '50251231165025123116', '2019-03-09 00:06:23'),
(17, '333971', '', '2019-03-10 00:53:20'),
(18, '333971', '', '2019-03-10 00:54:19'),
(19, '333971', '', '2019-03-10 01:11:22'),
(20, '333971', '', '2019-03-10 01:12:34'),
(21, '333971', '5025123116', '2019-03-10 01:40:25'),
(22, '333971', '5025123116245217149187', '2019-03-10 01:41:27'),
(23, '333971', '', '2019-03-10 01:47:21'),
(24, '333971', '', '2019-03-10 01:50:58'),
(25, '333971', '', '2019-03-10 01:52:00'),
(26, '333971', '5025123116', '2019-03-10 01:59:07'),
(27, '333971', '5025123116245217149187', '2019-03-10 01:59:36');

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `tarjeta`
--
ALTER TABLE `tarjeta`
  ADD PRIMARY KEY (`tar_id`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `tarjeta`
--
ALTER TABLE `tarjeta`
  MODIFY `tar_id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=28;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
