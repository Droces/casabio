<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\File;

use PHPExiftool\Driver\AbstractTag;

class PixelsPerMeterY extends AbstractTag
{

    protected $Id = 28;

    protected $Name = 'PixelsPerMeterY';

    protected $FullName = 'BMP::Main';

    protected $GroupName = 'File';

    protected $g0 = 'File';

    protected $g1 = 'File';

    protected $g2 = 'Image';

    protected $Type = 'int32u';

    protected $Writable = false;

    protected $Description = 'Pixels Per Meter Y';

}
