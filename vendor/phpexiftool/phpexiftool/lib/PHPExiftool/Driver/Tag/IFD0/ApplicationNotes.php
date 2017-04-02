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

class ApplicationNotes extends AbstractTag
{

    protected $Id = 700;

    protected $Name = 'ApplicationNotes';

    protected $FullName = 'PanasonicRaw::Main';

    protected $GroupName = 'IFD0';

    protected $g0 = 'EXIF';

    protected $g1 = 'IFD0';

    protected $g2 = 'Image';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'Application Notes';

    protected $flag_Binary = true;

    protected $flag_Unsafe = true;

}
