<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\JPEG;

use PHPExiftool\Driver\AbstractTag;

class DefineQuantizationTable extends AbstractTag
{

    protected $Id = 'DQT';

    protected $Name = 'DefineQuantizationTable';

    protected $FullName = 'JPEG::Main';

    protected $GroupName = 'JPEG';

    protected $g0 = 'JPEG';

    protected $g1 = 'JPEG';

    protected $g2 = 'Other';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Define Quantization Table';

}
