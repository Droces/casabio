<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\IFD0;

use PHPExiftool\Driver\AbstractTag;

class PanasonicRawVersion extends AbstractTag
{

    protected $Id = 1;

    protected $Name = 'PanasonicRawVersion';

    protected $FullName = 'PanasonicRaw::Main';

    protected $GroupName = 'IFD0';

    protected $g0 = 'EXIF';

    protected $g1 = 'IFD0';

    protected $g2 = 'Image';

    protected $Type = 'undef';

    protected $Writable = true;

    protected $Description = 'Panasonic Raw Version';

}
