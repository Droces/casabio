<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\RealPROP;

use PHPExiftool\Driver\AbstractTag;

class NumPackets extends AbstractTag
{

    protected $Id = 4;

    protected $Name = 'NumPackets';

    protected $FullName = 'Real::Properties';

    protected $GroupName = 'Real-PROP';

    protected $g0 = 'Real';

    protected $g1 = 'Real-PROP';

    protected $g2 = 'Video';

    protected $Type = 'int32u';

    protected $Writable = false;

    protected $Description = 'Num Packets';

}
